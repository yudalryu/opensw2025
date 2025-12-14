#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// SIGINT handler -> ls
void sigint_handler(int signo) {
    printf(" [SIGINT handler] === \n ");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        perror("execve ls");
        exit(1);
    } else { // parent
        wait(NULL);
    }
}

// SIGQUIT handler -> date
void sigquit_handler(int signo) {
    printf(" [SIGQUIT handler] === \n ");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/date", NULL};
        execve("/usr/bin/date", argv, NULL);
        perror("execve date");
        exit(1);
    } else { // parent
        wait(NULL);
    }
}

// SIGALRM handler -> whoami
void sigalrm_handler(int signo) {
    printf(" [SIGALRM handler] === \n ");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"/usr/bin/whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        perror("execve whoami");
        exit(1);
    } else { // parent
        wait(NULL);
        alarm(3); // 다시 alarm 설정
    }
}

int main() {

    // signal action 설정
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    // alarm 3초 설정
    alarm(3);

    // 무한 루프
    while (1) {
        pause(); // signal 대기
    }

    return 0;
}
