#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s [source file] [dest1] [dest2] ...\n", argv[0]);
        exit(0);
    }

    // source file open (read only)
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("source open");
        exit(1);
    }

    // dest files open
    int num_files = argc - 2;
    int *dest_fd_list = (int*)malloc(sizeof(int) * num_files);

    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i+2],
                               O_WRONLY | O_CREAT | O_TRUNC,
                               0644);
        if (dest_fd_list[i] == -1) {
            perror("dest open");
            close(src_fd);
            exit(1);
        }
    }

    // read + write loop
    char buffer[BUF_SIZE];
    ssize_t r;

    while (1) {
        r = read(src_fd, buffer, BUF_SIZE);

        if (r == 0) break;
        if (r < 0) {
            perror("read");
            break;
        }

        // write to stdout
        write(1, buffer, r);

        // write to each dest file
        for (int i = 0; i < num_files; i++) {
            write(dest_fd_list[i], buffer, r);
        }
    }

    // close all fd
    close(src_fd);
    
    for (int i = 0; i < num_files; i++) {
        close(dest_fd_list[i]);
    }

    free(dest_fd_list);
    return 0;
}
