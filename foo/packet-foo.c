#include "config.h"
#include <epan/packet.h>

#define FOO_PORT 1234

static int proto_foo = -1;

static dissector_handle_t foo_handle;

static int hf_foo_pdu_type = -1;
static int hf_foo_flags = -1;
static int hf_foo_sequenceno = -1;
static int hf_foo_initialip = -1;
static int ett_foo = -1;

static const value_string packettypenames[] = {
    {1, "Initialise"},
    {2, "Terminate"},
    {3, "Data"},
    {0, NULL}
};

#define FOO_START_FLAG 0x01
#define FOO_END_FLAG 0x02
#define FOO_PRIORITY_FLAG 0x04

#define FOO_SRC "MME"
#define FOO_DST "HSS"

static int hf_foo_startflag = -1;
static int hf_foo_endflag = -1;
static int hf_foo_priorityflag = -1;

static int
dissect_foo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_)
{
    gint offset = 0;
    guint8 packet_type = tvb_get_guint8(tvb, 0);

    col_set_str(pinfo->cinfo, COL_PROTOCOL, "FOO");
    /* clear out stuff in the info column */
    col_clear(pinfo->cinfo, COL_INFO);
    col_add_fstr(pinfo->cinfo, COL_INFO, "Type %s",
        val_to_str(packet_type, packettypenames, "Unkonwn (0x%02x)"));

    proto_item *ti = proto_tree_add_item(tree, proto_foo, tvb, 0, -1, ENC_NA);
    proto_item_append_text(ti, ", Type %s",
        val_to_str(packet_type, packettypenames, "Unkonwn (0x%02x)"));
    proto_tree *foo_tree = proto_item_add_subtree(ti, ett_foo);
    
    proto_tree_add_item(foo_tree, hf_foo_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset += 1;

    proto_tree_add_item(foo_tree, hf_foo_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(foo_tree, hf_foo_startflag, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(foo_tree, hf_foo_endflag, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(foo_tree, hf_foo_priorityflag, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset += 1;

    proto_tree_add_item(foo_tree, hf_foo_sequenceno, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset += 2;

    proto_tree_add_item(foo_tree, hf_foo_initialip, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset += 4;

    //set_address(&pinfo->src, AT_STRINGZ, (int)strlen(FOO_SRC)+1, FOO_SRC);
    //set_address(&pinfo->dst, AT_STRINGZ, (int)strlen(FOO_DST)+1, FOO_DST);

    set_address_tvb(&pinfo->net_src, AT_IPv4, 4, tvb, 0);
    copy_address_shallow(&pinfo->src, &pinfo->net_src);

    set_address_tvb(&pinfo->net_dst, AT_IPv4, 4, tvb, 4);
    copy_address_shallow(&pinfo->dst, &pinfo->net_dst);

    return tvb_captured_length(tvb);
}

void
proto_register_foo(void)
{
    static hf_register_info hf[] = {
        { &hf_foo_pdu_type,
            {"FOO PDU Type", "foo.type",
            FT_UINT8, BASE_DEC,
            VALS(packettypenames), 0x0,
            NULL, HFILL}
        },
        { &hf_foo_flags,
            {"FOO PDU Flags", "foo.flags",
            FT_UINT8, BASE_HEX,
            NULL, 0x0,
            NULL, HFILL}
        },
        { &hf_foo_startflag,
            {"FOO PDU Start Flags", "foo.flags.start",
            FT_BOOLEAN, 8,
            NULL, FOO_START_FLAG,
            NULL, HFILL}
        },
        { &hf_foo_endflag,
            {"FOO PDU End Flags", "foo.flags.end",
            FT_BOOLEAN, 8,
            NULL, FOO_END_FLAG,
            NULL, HFILL}
        },
        { &hf_foo_priorityflag,
            {"FOO PDU Priority Flags", "foo.flags.priority",
            FT_BOOLEAN, 8,
            NULL, FOO_PRIORITY_FLAG,
            NULL, HFILL}
        },
        { &hf_foo_sequenceno,
            {"FOO PDU Sequence Number", "foo.seqn",
            FT_UINT16, BASE_DEC,
            NULL, 0x0,
            NULL, HFILL}
        },
        { &hf_foo_initialip,
            {"FOO PDU Initial IP", "foo.initialip",
            FT_IPv4, BASE_NONE,
            NULL, 0x0,
            NULL, HFILL}
        },
    };

    /* Setup protocol sbutree array */
    static gint *ett[] = {
        &ett_foo
    };

    proto_foo = proto_register_protocol(
        "FOO Protocol", /* name */
        "FOO", /* short name */
        "foo" /* abbrev */
        );

    proto_register_field_array(proto_foo, hf, array_length(hf));
    proto_register_subtree_array(ett, array_length(ett));

    // foo_handle = create_dissector_handle(dissect_foo, proto_foo);
    foo_handle = register_dissector("foo", dissect_foo, proto_foo);
}

void
proto_reg_handoff_foo(void)
{
    dissector_add_uint("udp.port", FOO_PORT, foo_handle);
}

