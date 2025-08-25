// writer.c
#include <stdio.h>
#include <unistd.h>

int main() {
    int secret = 13579;

    printf("PID: %d\n", getpid());
    printf("Address of secret variable: %p\n", (void*)&secret);

    // Keep the program alive so we can inspect it
    while (1) {
        sleep(10);
    }
    return 0;
}
