#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int mysystem(const char *command)
{
    pid_t pid;
    int status;

    if (command == NULL)
        return 1;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return -1;
    }

    // Child process
    if (pid == 0) {
        // execl("/bin/sh", "sh", "-c", command, NULL)
        // system(3) 매뉴얼 DESCRIPTION 그대로 따라한 방식
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);

        // execl 실패 시 여기 도달
        perror("execl");
        exit(127);   // system()의 실패 코드와 동일
    }

    // Parent: wait child
    if (waitpid(pid, &status, 0) < 0) {
        perror("waitpid");
        return -1;
    }

    return status;
}

int main(void)
{
    // 아래 두 줄은 system과 동일한 동작 확인용
    // system("ls -l | wc -l");
    // system("find . -name \"*.c\"");

    mysystem("ls -l | wc -l");
    mysystem("find . -name \"*.c\"");

    printf("Good Bye~\n");

    return 0;
}
