#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *src, *dst;
    int fin, fout;
    size_t size;

    fin = open("foo", O_RDONLY);
    if (fin < 0) {
        perror("foo");
        exit(1);
    }

    size = lseek(fin, 0, SEEK_END);
}
