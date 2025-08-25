// reader.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <hex_address>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    unsigned long addr = strtoul(argv[2], NULL, 16);

    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/mem", pid);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (lseek(fd, addr, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    int value;
    if (read(fd, &value, sizeof(value)) != sizeof(value)) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Read value: %d\n", value);

    close(fd);
    return 0;
}
