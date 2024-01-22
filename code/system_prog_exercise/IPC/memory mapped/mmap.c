#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
int main(void)
{
    int fd;
    fd = open("mmap", O_RDWR);
    size_t size = getpagesize();
    char *data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, size);
    munmap(data, size);
}