#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t child_pid;
    int wstatus;

    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }

    // Child
    if (child_pid == 0) {
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        exit(7);   // status code = 7
    }

    // Parent
    printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());

    // wait child
    waitpid(child_pid, &wstatus, 0);

    if (WIFEXITED(wstatus)) {
        int code = WEXITSTATUS(wstatus);
        printf("Child exited with status code: %d\n", code);
    }

    return 0;
}
