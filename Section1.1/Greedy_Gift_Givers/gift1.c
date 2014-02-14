/*
ID: liudi192
LANG: C
TASK: gift1
*/
#include <stdio.h>
main() {
        FILE *fin = fopen("gift1.in","r");
        FILE *fout = fopen("gift1.out", "w");
        int NP;
	char names[10][14];
	int  spending[10];
        fscanf(fin,"%d",&NP);
	int i = 0;
	for(i = 0; i < NP; i++) {
		spending[i] = 0;
	}

	for(i = 0; i < NP; i++) {
		fscanf(fin,"%s",&names[i]);
	}
		
//	for(i = 0; i < NP; i++) {
//		printf("%s\n",&names[i]);
//	}
	char temp[14],current_name[14];
	int spd,num;
	int j,k;
	
	for(i = 0; i < NP; i++) {
		fscanf(fin,"%s", &temp);
		fscanf(fin,"%d %d",&spd,&num);
		if ( num > 0) {
			for(j = 0; j < num; j++) {
				fscanf(fin,"%s",&current_name);
				for(k = 0; k < NP; k++) {
					if (strcmp(current_name,names[k]) == 0) {
						spending[k] += 	spd / num;
					}
				}
			}
			for ( j = 0; j < NP; j++) {
				if( strcmp(temp,names[j]) == 0 ) {
					spending[j] -= (spd/num)*num;
				}
			}
		}	
	}
	for ( i = 0 ; i<NP;i++) {
		fprintf(fout,"%s %d\n",names[i],spending[i]);
	}
	exit(0);
}

