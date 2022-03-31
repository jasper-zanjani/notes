#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>

int main() 
{
const int SIZE = 4096;              // size of shared memory object (bytes)
const char *name = "OS";            // name of shared memory object
const char *message_0 = "Hello";
const char *message_1 = "World!";

int fd;     // shared memory file descriptor
char *ptr;  // pointer to shared memory object

    // create the shared memory object
    fd = shm_open(name, O_CREAT | O_RDWR, 0666); 

    // configure size of the shared memory object
    ftruncate(fd, SIZE);    

    // memory map the shared memory object
    ptr = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // write to shared memory object
    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}