#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    // 여러 파일 fd를 저장할 배열
    int fd_list[argc];
    int fd_count = 0;

    // argv[1]부터 파일 open 시도
    for(int i = 1; i < argc; i++){
        int fd = open(argv[i], O_RDONLY);   // 조건 3: read only mode

        if(fd == -1){
            // 조건 4-2: open 실패 → perror
            perror(argv[i]);
        } 
        else {
            printf("open success: %s (fd=%d)\n", argv[i], fd);
            fd_list[fd_count] = fd;  // store only successful descriptors
            fd_count++;
        }
    }

    // 조건 5: open 성공된 파일만 close
    for(int i = 0; i < fd_count; i++){
        close(fd_list[i]);
    }

    return 0;
}
