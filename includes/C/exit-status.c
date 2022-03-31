#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status;
    if (fork()) {
        printf("parent waiting for child ... \n");
        wait(&status);
        if (WIFEXITED(status))
            printf("child ended normally, exit status = %d\n", WEXITSTATUS(status));
        if (WIFSIGNALED(status))
            printf("child terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("child running -- PID is %d\n", getpid());
        sleep(50);
        exit(3);
    }
}