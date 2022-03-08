#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void get_6_ram(int t, FILE *fp) {
    fprintf(fp,"[%d]: ",t);
    int i, n, j, temp;
    srand((unsigned)time(NULL)+t);
    int num[7];
    for ( i = 0 ; i<7 ; i++) {
        temp = ((rand() % 69) +1);
        for(n=0 ; n<i ; n++) {
            if(temp == num[n]){
                i--;
                break;
            }
        }
        if(temp!=num[n]) {
            num[i] = temp;
        }
    }
        for(int a=0 ; a<6; a++) {
            for(int b=a+1; b<6; b++) {
                if (num[a]>num[b]) {
                    int tmp = num[a];
                    num[a] =num[b];
                    num[b] = tmp;
            }
        }
    }

    for(i=0 ; i<7; i++) {
        num[6] = ((rand() % 10) +1);
        fprintf(fp,"%02d ",num[i]);
    }
    
    fprintf(fp,"\n");
}


int main() {
    FILE *fp;
    fp = fopen("lotto.txt","w+");
    int i,t;
    printf(" Welcome, please enter how many lotteries you want to buy?");
    scanf("%d", &i);
    fprintf(fp, "======== lotto649 ========\n");
    //printf("=%s=", ctime(&curtime));
    //get_curtime;
    time_t curtime;
    time(&curtime);
    char* now = ctime(&curtime);
    now[strlen(now)-1] = 0;
    
    fprintf(fp,"=%s=\n",now);
    for(t=1; t<6; t++) {
        if(t<=i) {
            get_6_ram(t,fp);
        }
        else {
            fprintf(fp, "[%d]: -- -- -- -- -- -- --\n",t);
        }
    }
    fprintf(fp,"======== csie@CGU ========\n");
    
}


