#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    char *c = (char *)malloc(size * sizeof(char));
    FILE *fp = fopen("/usr/lib/locale/locale-archive", "r");
    fread(c, size, 1, fp);
    printf("called fread(fp, c, %d).  returned that"
           "bytes  were read.\n",
           size);

    close(fp);
    free(c);
    return 0;
}
