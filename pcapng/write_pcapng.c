#include <stdio.h> 

typedef unsigned char vos_uint8;

int main()
{
    vos_uint8 auc_shb_little_tcp[] = {
        0x0A, 0x0D, 0x0D, 0x0A, // block type
        0x1C, 0x00, 0x00, 0x00, // block total length
        0x4d, 0x3c, 0x2b, 0x1a, // byte-order magic
        0x01, 0x00, 0x00, 0x00, // major version | minor version
        0xff, 0xff, 0xff, 0xff, // section length
        0xff, 0xff, 0xff, 0xff, // section length
        0x1C, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_idb_little_tcp[] = {
        0x01, 0x00, 0x00, 0x00, // block type
        0x14, 0x00, 0x00, 0x00, // block total length
        0x93, 0x00, 0x00, 0x00, // link typ | reserved
        0x00, 0x00, 0x04, 0x00, // snaplen
        0x14, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_epb_little_tcp[] = {
        0x06, 0x00, 0x00, 0x00, // block type
        0x48, 0x00, 0x00, 0x00, // block total length
        0x00, 0x00, 0x00, 0x00, // interface id
        0xfd, 0x75, 0x05, 0x00, // timestamp(high)
        0x71, 0xc9, 0x6a, 0x6c, // timestamp(low)
        0x28, 0x00, 0x00, 0x00, // captured len
        0x28, 0x00, 0x00, 0x00, // packet len
        0xdb, 0x62, 0x0c, 0xea, // packet data
        0xcc, 0xd8, 0xbb, 0x4d, 
        0x00, 0x00, 0x00, 0x00, 
        0xa0, 0x02, 0x80, 0x18,
        0xba, 0x51, 0x00, 0x00, 
        0x02, 0x04, 0x40, 0x0c, 
        0x04, 0x02, 0x08, 0x0a, 
        0x00, 0xf0, 0xde, 0x8e,
        0x00, 0x00, 0x00, 0x00, 
        0x01, 0x03, 0x03, 0x06, // packet data
        0x48, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_shb_little_mysql[] = {
        0x0A, 0x0D, 0x0D, 0x0A, // block type
        0x1C, 0x00, 0x00, 0x00, // block total length
        0x4d, 0x3c, 0x2b, 0x1a, // byte-order magic
        0x01, 0x00, 0x00, 0x00, // major version | minor version
        0x40, 0x00, 0x00, 0x00, // section length
        0x00, 0x00, 0x00, 0x00, // section length
        0x1C, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_idb_little_mysql[] = {
        0x01, 0x00, 0x00, 0x00, // block type
        0x14, 0x00, 0x00, 0x00, // block total length
        0x94, 0x00, 0x00, 0x00, // link typ | reserved
        0x00, 0x00, 0x04, 0x00, // snaplen
        0x14, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_epb_little_mysql[] = {
        0x06, 0x00, 0x00, 0x00, // block type
        0x2c, 0x00, 0x00, 0x00, // block total length
        0x00, 0x00, 0x00, 0x00, // interface id
        0xfd, 0x75, 0x05, 0x00, // timestamp(high)
        0x71, 0xc9, 0x6a, 0x6c, // timestamp(low)
        0x0b, 0x00, 0x00, 0x00, // captured len
        0x0b, 0x00, 0x00, 0x00, // packet len
        0x07, 0x00, 0x00, 0x01, // packet data
        0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00, 0x00, // packet data, one padding
        0x2c, 0x00, 0x00, 0x00  // block total length
    };

    vos_uint8 auc_shb_big_mysql[] = {
        0x0A, 0x0D, 0x0D, 0x0A, // block type
        0x00, 0x00, 0x00, 0x1c, // block total length
        0x1a, 0x2b, 0x3c, 0x4d, // byte-order magic
        0x00, 0x01, 0x00, 0x00, // major version | minor version
        0xff, 0xff, 0xff, 0xff, // section length
        0xff, 0xff, 0xff, 0xff, // section length
        0x00, 0x00, 0x00, 0x1c  // block total length
    };

    vos_uint8 auc_idb_big_mysql[] = {
        0x00, 0x00, 0x00, 0x01, // block type
        0x00, 0x00, 0x00, 0x14, // block total length
        0x00, 0x94, 0x00, 0x00, // link typ | reserved
        0x00, 0x00, 0x04, 0x00, // snaplen
        0x00, 0x00, 0x00, 0x14  // block total length
    };

    vos_uint8 auc_epb_big_mysql[] = {
        0x00, 0x00, 0x00, 0x06, // block type
        0x00, 0x00, 0x00, 0x2c, // block total length
        0x00, 0x00, 0x00, 0x00, // interface id
        0x00, 0x05, 0x75, 0xfd, // timestamp(high)
        0x6c, 0x6a, 0xc9, 0x71, // timestamp(low)
        0x00, 0x00, 0x00, 0x0b, // captured len
        0x00, 0x00, 0x00, 0x0b, // packet len
        0x07, 0x00, 0x00, 0x01, // packet data
        0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00, 0x00, // packet data, one padding
        0x00, 0x00, 0x00, 0x2c  // block total length
    };

    

    FILE *fd_little_tcp     = fopen("little_tcp.pcapng", "w");
    FILE *fd_little_mysql   = fopen("little_mysql.pcapng", "w");
    FILE *fd_big_mysql      = fopen("big_mysql.pcapng", "w");
    FILE *fd_multi_shb      = fopen("multi_shb.pcapng", "w");

    fwrite(auc_shb_little_tcp, 1, sizeof(auc_shb_little_tcp), fd_little_tcp);
    fwrite(auc_idb_little_tcp, 1, sizeof(auc_idb_little_tcp), fd_little_tcp);
    fwrite(auc_epb_little_tcp, 1, sizeof(auc_epb_little_tcp), fd_little_tcp);

    fwrite(auc_shb_little_mysql, 1, sizeof(auc_shb_little_mysql), fd_little_mysql);
    fwrite(auc_idb_little_mysql, 1, sizeof(auc_idb_little_mysql), fd_little_mysql);
    fwrite(auc_epb_little_mysql, 1, sizeof(auc_epb_little_mysql), fd_little_mysql);

    fwrite(auc_shb_big_mysql, 1, sizeof(auc_shb_big_mysql), fd_big_mysql);
    fwrite(auc_idb_big_mysql, 1, sizeof(auc_idb_big_mysql), fd_big_mysql);
    fwrite(auc_epb_big_mysql, 1, sizeof(auc_epb_big_mysql), fd_big_mysql);

    fwrite(auc_shb_little_tcp, 1, sizeof(auc_shb_little_tcp), fd_multi_shb);
    fwrite(auc_idb_little_tcp, 1, sizeof(auc_idb_little_tcp), fd_multi_shb);
    fwrite(auc_epb_little_tcp, 1, sizeof(auc_epb_little_tcp), fd_multi_shb);
    fwrite(auc_shb_big_mysql,  1, sizeof(auc_shb_big_mysql),  fd_multi_shb);
    fwrite(auc_idb_big_mysql,  1, sizeof(auc_idb_big_mysql),  fd_multi_shb);
    fwrite(auc_epb_big_mysql,  1, sizeof(auc_epb_big_mysql),  fd_multi_shb);

    fclose(fd_little_tcp);
    fclose(fd_little_mysql);
    fclose(fd_big_mysql);
    fclose(fd_multi_shb);

    return 0;
}