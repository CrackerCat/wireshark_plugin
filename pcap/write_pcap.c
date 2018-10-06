#include <stdio.h> 

typedef unsigned char vos_uint8;

int main()
{
    vos_uint8 auc_little_file_header[] = {
        0xd4, 0xc3, 0xb2, 0xa1, // magic
        0x02, 0x00, 0x04, 0x00, // major version | minor version
        0x00, 0x00, 0x00, 0x00, // thiszone
        0x00, 0x00, 0x00, 0x00, // sigfigs
        0x00, 0x40, 0x00, 0x00, // snaplen
        0x94, 0x00, 0x00, 0x00, // link type
    };

    vos_uint8 auc_little_pkt_header[] = {
        0x10, 0xe6, 0xb9, 0x05, // timestamp(s)
        0x31, 0x2c, 0x0a, 0x00, // timestamp(us)
        0x0b, 0x00, 0x00, 0x00, // caplen
        0x0b, 0x00, 0x00, 0x00, // len
    };

    vos_uint8 auc_big_file_header[] = {
        0xa1, 0xb2, 0xc3, 0xd4, // magic
        0x00, 0x02, 0x00, 0x04, // major version | minor version
        0x00, 0x00, 0x00, 0x00, // thiszone
        0x00, 0x00, 0x00, 0x00, // sigfigs
        0x00, 0x00, 0x04, 0x00, // snaplen
        0x00, 0x00, 0x00, 0x94, // link type
    };

    vos_uint8 auc_big_pkt_header[] = {
        0x05, 0xb9, 0xe6, 0x10, // timestamp(s)
        0x00, 0x0a, 0x2c, 0x31, // timestamp(us)
        0x00, 0x00, 0x00, 0x0b, // caplen
        0x00, 0x00, 0x00, 0x0b, // len
    };

    vos_uint8 auc_pkt_data[] = {
        0x07, 0x00, 0x00, 0x01,
        0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00
    };

    FILE *fd_little_mysql   = fopen("little_mysql.pcap", "w");
    FILE *fd_big_mysql      = fopen("big_mysql.pcap", "w");

    fwrite(auc_little_file_header, 1, sizeof(auc_little_file_header), fd_little_mysql);
    fwrite(auc_little_pkt_header,  1, sizeof(auc_little_pkt_header),  fd_little_mysql);
    fwrite(auc_pkt_data,           1, sizeof(auc_pkt_data),           fd_little_mysql);

    fwrite(auc_big_file_header, 1, sizeof(auc_big_file_header), fd_big_mysql);
    fwrite(auc_big_pkt_header,  1, sizeof(auc_big_pkt_header),  fd_big_mysql);
    fwrite(auc_pkt_data,        1, sizeof(auc_pkt_data),        fd_big_mysql);


    fclose(fd_little_mysql);
    fclose(fd_big_mysql);

    return 0;
}