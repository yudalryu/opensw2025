#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    // 조건 1, 2: 사용법 체크
    if (argc < 2) {
        printf("Usage: %s <program path> [OPTION]...\n", argv[0]);
        exit(0);
    }

    // fork
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // Child
    if (pid == 0) {
        // execve는 argv 형식 그대로 사용 가능
        // 단, argv[1]이 실제 실행할 프로그램 경로
        // execve의 두 번째 인자는 "프로그램 이름 포함" 형태의 argv 배열 필요

        char **new_argv = &argv[1];   // program path + options
        char *envp[] = { NULL };      // 기본 환경 변수 없음

        execve(argv[1], new_argv, envp);

        // execve 실패 시 여기 도달
        perror("execve");
        exit(1);     // 조건 4
    }

    // Parent: waitpid
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        int code = WEXITSTATUS(status);
        printf("Child exited with status code: %d\n", code);
    }

    return 0;
}
