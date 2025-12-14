#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();

    while (1) {
        printf("Process ID: %d\n", pid);
        sleep(1);   // 1초 간격
    }

    return 0;
}
