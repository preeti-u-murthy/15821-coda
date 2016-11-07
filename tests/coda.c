#include<stdio.h>
void main()
{
    FILE *fp;

    fp = fopen("/coda/testserver.coda.cs.cmu.edu/WELCOME", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    
    int cur_pos = fseek(fp, -300, SEEK_END);
    if (cur_pos == -1) {
        printf("Cound not seek\n");
    } else {
        printf("Current seek position is %d\n", cur_pos);
    }

    char buf[200];
    int num_bytes = fread(buf, 1, sizeof(buf), fp);
    printf("Number of bytes read=%d\n", num_bytes);

    /*
    cur_pos = fseek(fp, -200, SEEK_END);
    if (cur_pos == -1) {
        printf("Cound not seek\n");
    } else {
        printf("Current seek position is %d\n", cur_pos);
    }

    num_bytes = fread(buf, 1, sizeof(buf), fp);
    printf("Number of bytes read=%d\n", num_bytes);

    
    while (num_bytes > 0) {
        printf("Number of bytes read=%d\n", num_bytes);
        num_bytes = fread(buf, 1, sizeof(buf), fp);
        if (num_bytes < sizeof(buf)) {
            printf("Short read of %d bytes\n", num_bytes);
            fclose(fp);
            return;
        }
    }*/
    fclose(fp);
}
