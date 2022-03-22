#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
FILE *binfile;
FILE *operator_id;
FILE *recordsFile;
static int o;
static int currentCount;
static int operaterNum;
static char date[32];
static char Time[32];



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

typedef struct lotto_record {
    int lotto_no;//currentCount
    int lotto_receipt;//currentCount*50*1.1
    int emp_Id;//o
    char lotto_date[32];//date
    char lotto_time[32];//time
} lotto_record_t;

void cutTime(){
    time_t now = time(0);
    strftime(date, 32,"%Y%m%d", localtime(&now));
    strftime(Time, 32,"%Y%m%d", localtime(&now));
}

void records(int o) {
    lotto_record_t l;
    l.lotto_no = currentCount;
    l.lotto_receipt = currentCount*50*1.1;
    l.emp_Id = o;
    strcpy(l.lotto_date, date); 
    strcpy(l.lotto_time, Time);
    
    recordsFile = fopen("records.bin","ab");
    fwrite(&l, sizeof(l), 1, recordsFile);//要記熟用法
    fclose(recordsFile);
} 

int main() {
    
    char currentName[80];
    int i ,t ;
    count();
    sprintf(currentName, "lotto[%04d].txt", currentCount);
    fp = fopen(currentName,"w+");
    printf(" Welcome, please enter your operator ID:");
    scanf("%d", &o);
    printf("Please enter how many lotteries do you want to buy?");
    scanf("%d", &i);
    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp,"======== No.%05d ========\n", currentCount);
    
    //time_t now;
    //time(&now);
    //char* dt = ctime(&now);
    //dt[strlen(now)-1] = 0;
    //fprintf(fp,"=%s=\n",now);
    
    for(t=1; t<6; t++) {
        if(t<=i) {
            get_6_ram(t,fp);
        }
        else {
            fprintf(fp, "[%d]: -- -- -- -- -- -- --\n",t);
        }
        
    }
    int write[1]={0};
    operator_id = fopen("operator_id.txt", "wb+");
    write[0] = o;
    fwrite(write, sizeof(int), 1, operator_id);
    fclose(operator_id);
    operaterNum = write[0];
    fprintf(fp,"======== No.%05d ========\n", operaterNum);
    fprintf(fp,"======== csie@CGU ========\n");
    fclose(fp);
    cutTime();
    records(o);
    
}
