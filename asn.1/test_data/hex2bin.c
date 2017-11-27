#include <stdio.h>

unsigned char hex2dec(char c);

int main()
{
    FILE *fp_hex = fopen("s1_setup.hex", "r");
    FILE *fp_bin = fopen("s1_setup.pcap", "wb");
    int c = fgetc(fp_hex);
    unsigned char val = 0;
    unsigned char ret = 0;
    while(c != EOF)
    {
        if((c == ' ') || (c == '\n'))
        {
            fwrite(&val, 1, 1, fp_bin);
            val = 0;
        }
        else
        {
            ret = hex2dec(c);
            if(0xFF == ret)
            {
                printf("error\n");
            }
            else
            {
                val = (val << 4) + ret;
            }
        }
        c = fgetc(fp_hex);
    }
}

unsigned char hex2dec(char c)
{
    if((c >= '0') && (c <= '9'))
    {
        return (c - '0');
    }
    if((c >= 'A') && (c <= 'F'))
    {
        return (c - 'A') + 10;
    }
    if((c >= 'a') && (c <= 'f'))
    {
        return (c - 'a') + 10;
    }

    return 0xFF;
}