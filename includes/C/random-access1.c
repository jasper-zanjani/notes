#include <unistd.h>
#include <fcntl.h>

struct record {
    int id;
    char name[80];
};

void main()
{
    int fd, size = sizeof(struct record);
    struct record info;

    fd = open("datafile", O_RDWR);
    lseek(fd, size, SEEK_SET);
    read(fd, &info, size);
    
    info.id = 99;
    lseek(fd, -size, SEEK_CUR);
    write(fd, &info, size);

    close(fd);
}