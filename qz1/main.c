#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
FILE *binfile;
static int currentCount;

void get_6_ram(int t, FILE *fp) {
    int i, n, j, temp;
    fprintf(fp,"[%d]: ",t);
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

void count() {
    int read[1];
    int write[1];
    if((binfile = fopen("binfile.txt","r")) == NULL) {
        binfile = fopen("binfile.txt","wb+");
        write[0] = 1;
        fwrite(write,sizeof(int),1,binfile);
    }
    else{
        binfile = fopen("binfile.txt","rb+");
        fseek(binfile, 0, SEEK_SET);
        fread(read,sizeof(int),1,binfile);
        fclose(binfile);    
        write[0] = read[0] + 1;
        binfile = fopen("binfile.txt", "wb+");
        fwrite(write, sizeof(int), 1, binfile);
    }
    fclose(binfile);
    currentCount = write[0];
}  

    


int main() {
    count();
    char currentName[80];
    int i,t;
    sprintf(currentName, "lotto[%04d].txt", currentCount);
    fp = fopen(currentName,"w+");
    printf(" Welcome, please enter how many lotteries do you want to buy?");
    scanf("%d", &i);
    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp,"======== No.%05d ========\n", currentCount);
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
    fclose(fp);
    
}

