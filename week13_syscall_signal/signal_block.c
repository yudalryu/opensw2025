#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct two_double{
    double a;
    double b;
};

struct two_double data;

void sigint_handler(int signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){

    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0};
    struct two_double ones  = {1.0, 1.0};

    sigset_t block_set, prev_set;

    // SIGALRM handler 설정
    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1) {
        perror("sigaction error");
        exit(1);
    }

    // block할 signal 집합 설정
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);

    alarm(1);

    while (1) {
        // block SIGALRM
        sigprocmask(SIG_BLOCK, &block_set, &prev_set);
        data = zeros;
        // unblock SIGALRM
        sigprocmask(SIG_SETMASK, &prev_set, NULL);

        // block SIGALRM
        sigprocmask(SIG_BLOCK, &block_set, &prev_set);
        data = ones;
        // unblock SIGALRM
        sigprocmask(SIG_SETMASK, &prev_set, NULL);
    }

    return 0;
}
