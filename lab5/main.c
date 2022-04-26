#include <stdio.h>
#include <stdlib.h>


int* get_int_array(int n) {
    return (int*)calloc(n, sizeof(int));
}

void set_value(int* p, int v) {
    *p = v;
}

void print_array(int* p, int n) {
    for (int i=0; i<n; i++) {
        if (i == (n-1)) {
            printf("%d]\n", *p+i);
            break;
        } printf("%d, ", *p+i);
    }
}

typedef struct array_list {
    int n;
    int (*func_ptr_get)(int);
    int (*func_ptr_set)(int, int);
    int (*func_ptr_print)(int, int);
} array_list_t;

int main() {
    int n = 10;
    int* ip = get_int_array(n);
    
    for (int i=0; i<n; i++) {
        set_value(ip+i, i+1);
    }
    

    printf("No.1-----------\n[");
    print_array(ip, n);
    printf("No.1-----------\n");
    printf("No.1-----------\n");
    return 0;
}
