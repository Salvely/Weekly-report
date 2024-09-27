#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    char s[200];

    // craete the fifo
    mknod("myfifo", S_IFIFO | 0644, 0);

    // open the fifo
    int fd = open("myfifo", O_RDONLY);

    int r_count;
    // write something to it
    do
    {
        r_count = read(fd, s, sizeof(s));
        if (r_count == -1)
        {
            perror("read");
            exit(1);
        }
        else
        {
            s[r_count] = '\0';
            printf("read %d bytes from fifo: %s\n", r_count, s);
        }
    } while (r_count > 0);
    return 0;
}