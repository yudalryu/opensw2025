#include <stdio.h>
#include <unistd.h>   // getpid(), getppid()

int main(void){
    pid_t pid, ppid;

    pid = getpid();   // 현재 프로세스의 PID 반환
    ppid = getppid(); // 부모 프로세스의 PID 반환
    printf("My PID: %d\n", pid);
    printf("My Parent PID: %d\n", ppid);

    return 0;
}
