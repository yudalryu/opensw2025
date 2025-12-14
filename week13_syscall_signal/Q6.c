#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {

    sigset_t block_set, pending_set;

    // 1️⃣ SIGINT block 설정
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    // 2️⃣ 5초 sleep
    sleep(5);

    // 3️⃣ pending signal 확인
    sigpending(&pending_set);

    if (sigismember(&pending_set, SIGINT)) {
        printf("SIGINT is pending\n");
    } else {
        printf("SIGINT is not pending\n");
    }

    return 0;
}
