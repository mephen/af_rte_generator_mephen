#include "stdio.h"

typedef struct{
    int* a;
    char b;
} test_type;

int main(){
    int arr[3];
    int* arr_addr = arr;
    int** p = &arr_addr;
    printf("%d\n", arr);
    printf("%d\n", &arr);
    printf("%d\n", arr_addr);
    printf("%d\n", &arr_addr);
    printf("%d\n", p);
    return 0;
}