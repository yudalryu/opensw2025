#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]){

    // 조건 1 + 최소 인자 3개 필요
    if(argc < 3){
        printf("Usage: %s <source file> <dest1> <dest2> ...\n", argv[0]);
        return 1;
    }

    char *src = argv[1];

    // 조건 2: source file MUST exist (read only)
    int fd_src = open(src, O_RDONLY);
    if(fd_src == -1){
        perror(src);
        return 1;
    }

    // destination 파일 개수 = argc - 2
    int dest_count = argc - 2;
    int fd_list[dest_count];

    // 조건 5: dest 파일들 write only + create + 권한 0644
    for(int i = 0; i < dest_count; i++){
        fd_list[i] = open(argv[i+2],
                          O_WRONLY | O_CREAT | O_TRUNC,
                          0644);   // user rw-, group r--, others r--

        if(fd_list[i] == -1){
            perror(argv[i+2]);
            // dest open 실패해도 다른 dest는 계속 open해야 하므로 종료 X
        }
    }

    // 조건 4: src에서 32 bytes씩 읽어서
    //         → 모든 dest + stdout에 동시에 write
    char buffer[BUF_SIZE];
    ssize_t n;

    while(1){
        n = read(fd_src, buffer, BUF_SIZE);

        // EOF
        if(n == 0){
            break;
        }

        // read 에러
        if(n < 0){
            perror("read");
            break;
        }

        // stdout(1)에 write
        write(1, buffer, n);

        // 각 dest 파일에 write
        for(int i = 0; i < dest_count; i++){
            if(fd_list[i] != -1){
                write(fd_list[i], buffer, n);
            }
        }
    }

    // 파일 닫기
    close(fd_src);
    for(int i = 0; i < dest_count; i++){
        if(fd_list[i] != -1){
            close(fd_list[i]);
        }
    }

    return 0;
}
