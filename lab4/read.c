#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

extern int errno;
int main(int argc, char *argv[])
{
    int byte;
    int size;
    char *c;
    int fp = open("/usr/lib/locale/locale-archive", O_RDONLY);
    if (argc >= 2)
    {
        size = atoi(argv[1]);
    }
    c = (char *)malloc(size * sizeof(char));

    if (fp == EOF)
    {
        printf("error %d", errno);
        exit(1);
    }

    byte = read(fp, c, size);
    printf("called read(%d, c, %d).  returned that"
           " %d bytes  were read.\n",
           fp, size, byte);

    close(fp);
    free(c);
    return 0;
}