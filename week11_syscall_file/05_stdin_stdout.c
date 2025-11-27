#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 128

int main(void){
    char buffer[BUF_SIZE];
    ssize_t n;

    while(1){
        // 조건 1: stdin(0)에서 read
        n = read(0, buffer, BUF_SIZE);

        // 조건 2: Ctrl+D → read 결과 0 → 루프 종료
        if(n == 0){
            break;
        }

        // read error 처리 (선택적)
        if(n < 0){
            perror("read");
            break;
        }

        // 조건 1: read한 내용을 그대로 stdout(1)에 write
        write(1, buffer, n);
    }

    return 0;
}
