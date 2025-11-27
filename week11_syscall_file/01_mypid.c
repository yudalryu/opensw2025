#include <stdio.h>
#include <unistd.h>   // getpid()

int main(void){
    pid_t pid;

    pid = getpid();   // 현재 프로세스의 PID 반환
    printf("My PID: %d\n", pid);

    return 0;
}
