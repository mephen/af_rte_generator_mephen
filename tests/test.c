#include "stdio.h"

int main() {
    MAIN:
        printf("Hello, World!\n");
    goto MAIN;
    return 0;
}