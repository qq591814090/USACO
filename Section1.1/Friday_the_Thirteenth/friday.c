/*
ID: liudi192
LANG: C
TASK: friday
*/
#include <stdio.h>
main() {
	FILE *fin = fopen("friday.in","r");
	FILE *fout = fopen("friday.out","w");
	int N;
	fscanf(fin,"%d",&N);
	int odd_year[13];
	int even_year[13];
	int week[7];
	int *p;
	odd_year[1] = 31;
	odd_year[2] = 28;
	odd_year[3] = 31;
	odd_year[4] = 30;
	odd_year[5] = 31;
	odd_year[6] = 30;
	odd_year[7] = 31;
	odd_year[8] = 31;
	odd_year[9] = 30;
	odd_year[10] = 31;
	odd_year[11] = 30;
	odd_year[12] = 31;
	int i,j;
	int past_days = 0;
	for( i = 0; i< 7; i++) {
		week[i] = 0;
	}

	for( i =1; i <13;i++) {
		if (i == 2) {
			even_year[i] = odd_year[i] +1;
		} else
		{
			even_year[i] = odd_year[i];
		}
	}
	int even_flag = 0;
	for( i = 0; i< N;i++) {
		if ( ( ((1900 + i)%100 != 0 ) && ((1900+i)%4 ==0)) ||((1900+i)%400 ==0)) {
			even_flag = 1;
		} else
		{
			even_flag = 0;
		}
		if (even_flag == 1) {
			p = &even_year[1];
		} else
		{
			p = &odd_year[1];
		}
		
		for( j= 1; j < 13; j++) {
			week[(past_days + 13)%7]++;
			past_days += *p;
			p++;
	//		printf("%d\n",past_days);
		}
	}
//	printf("%d\n",N);
	fprintf(fout,"%d %d %d %d %d %d %d\n",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
	exit(0);
}			 
