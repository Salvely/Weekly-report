#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <signal.h>

void sigint_handler(int sig)
{
    const char msg[] = "Ahh!Sigint!\n";
    write(0, msg, sizeof(msg));
}
int main(void)
{
    char s[200];
    struct sigaction sa =
        {
            sigint_handler,
            .sa_flags = SA_RESTART,
            0,
        };
    if (sigaction(SIGINT, &sa, NULL))
    {
        perror("sigaction");
        exit(1);
    }
    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL)
    {
        perror("fgets");
    }
    else
    {
        printf("You entered: %s\n", s);
    }
    return 0;
}