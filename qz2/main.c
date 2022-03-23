#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

FILE* reportFile;
FILE* recordsFile;
static char date[32];

void cutTime(){
    time_t now = time(0);
    strftime(date, 32,"%Y%m%d", localtime(&now));
    //strftime(Time, 32,"%Y%m%d", localtime(&now));
}

typedef struct lotto_record {
    int lotto_no;//currentCount
    int lotto_receipt;//currentCount*50*1.1
    char lotto_date[32];//date
} lotto_record_t;

//void records() {
    
    //lotto_record_t l;
    //l.lotto_no; //currentCount
    //l.lotto_receipt = currentCount*50*1.1;
    //strcpy(l.lotto_date, date);
    //fwrite(&l, sizeof(l), 1, recordsFile);//要記熟用法
    //fclose(recordsFile);
//} 


int main() {
    
    recordsFile = fopen("records.bin", "r");
    reportFile = fopen("reportFile.txt", "w+");
    
    cutTime();

    lotto_record_t tmp[1];
    int i = 0;
    
    while (fread(&tmp[i], sizeof(lotto_record_t), 1, recordsFile)) {
        i++;
    }
    //i--;
    
    int no = 0;
    int dateSum = 0, noSum, setsSum = 0, receiptSum = 0;
    int j = 0, r = 0;
    
    fprintf(reportFile, "========= lotto649 Report =========\n");
    fprintf(reportFile, "- Date ------ Num. ------ Receipt -\n");
    
    while (j <= i){
        int sets = 0; // lotto_receipt/55
		int receipt = 0; // =lotto_receipt
		while(strcmp(tmp[j].lotto_date, tmp[j+1].lotto_date) == 0)j++;
		
		for(; r <= j; r++){
			sets = sets + (tmp[r].lotto_receipt/55);
			receipt = receipt + tmp[r].lotto_receipt;
		}
		r--;
		no = tmp[r].lotto_no - no;
		
		dateSum ++;
		setsSum = setsSum + sets;
		receiptSum = receiptSum + receipt;
		
        fprintf(reportFile, "%s\t%d/%d\t\t%d\n",tmp[0].lotto_date,
                                                no,
                                                sets,
                                                receipt);
        no = tmp[r].lotto_no;
        j++;
    }
    
    fprintf(reportFile,"----------------------------------\n");
    fprintf(reportFile, "%d\t%d/%d\t\t%d\n",dateSum,
                                            tmp[i].lotto_no,
                                            setsSum,
                                            receiptSum);
    fprintf(reportFile, "======== %s Printed =========", date);
    

    fclose(reportFile);
    fclose(recordsFile);
}
