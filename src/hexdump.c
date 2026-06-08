#include <stdio.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("usage: ./hexdump <file>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file){
        printf("failed to open file: %s\n", argv[1]);
        return 1;
    }
    

    int byte;
    long offset = 0;
    unsigned char row[16];
    int rowLen = 0;

    while((byte = fgetc(file))!= EOF){
        if(offset % 16 == 0){
            printf("%08lx  ", offset);
        }

        printf("%02x ", byte);
        row[rowLen] = (unsigned char)byte;
        rowLen++;

        if ((offset + 1) % 16 == 0) {
            printf(" | ");
            for (int i = 0; i < rowLen; i++)
                printf("%c", (row[i] >= 32 && row[i] < 127) ? row[i] : '.');
            printf("\n");
            rowLen = 0;
        }

        offset ++;


    }

    // displays any left over on uncompleted line
    if (rowLen > 0) {
        for (int i = rowLen; i < 16; i++)
            printf("   ");
        printf(" | ");
        for (int i = 0; i < rowLen; i++)
            printf("%c", (row[i] >= 32 && row[i] < 127) ? row[i] : '.');
        printf("\n");
    }

    printf("\n");
    fclose(file);
    return 0;
}