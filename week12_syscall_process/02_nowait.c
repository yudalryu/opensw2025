#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // Child
    if (pid == 0) {
        printf("Child start: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(1);  // parent보다 늦게 종료되도록

        printf("Child end:   PID=%d, PPID=%d\n", getpid(), getppid());
        exit(7);
    }

    // Parent
    printf("Parent: PID=%d, PPID=%d (즉시 종료)\n", getpid(), getppid());
    exit(0);  // waitpid 안 함
}
