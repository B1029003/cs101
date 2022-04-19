#include <stdio.h>
int swap(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
    printf("after swap, n=%d, m=%d", *i, *j);
}

void swapArray(int* source, int* dest, int size) {
    int tmp;
    tmp = *source;
    for (int i=0, int j=0; i<size; i++) {
        source[i] = *dest[j++];
    }
    for (int i=0, int j=0; i<size; i++) {
        dest[i] = *tmp[j++];
    }
}

void printArray(int* array, size) {
    for(int i = 0; i <size; i++) {
        printf("%d\n",*(array+1));
    }
    
}

int main() {
    int n, m;
    n = 1;
    m =2;
    swap(&n, &m);
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    return 0;
}
