#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

struct record {
    int id;
    char name[80];
}

int main() 
{
    int fd;
    size_t size;
    struct record *records;

    fd = open("foo", O_RDWR);
    size = lseek(fd, 0, SEEK_END);
    records = (struct record *) mmap (NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    records[1].id = 99;
    msync(records, size, MS_SYNC);
}