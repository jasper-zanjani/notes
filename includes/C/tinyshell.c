#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
    char line[100];

    while (printf("> "), gets(line) != NULL) {
        if (fork() == 0) {
            execlp(line, line, (char *)0);

            printf("%s: not found\n", line);
            exit(1);
        } else wait(0);
    }
}