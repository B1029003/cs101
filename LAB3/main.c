#include <stdio.h>
int my_strlen(char* s) {
    for (int i = 0; ; i++) {
        if(s[i] == 0) return i;
    }    
}    

int main() {
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    return 0;
}
