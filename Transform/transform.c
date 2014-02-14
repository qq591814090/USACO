/*
ID: liudi192
LANG: C
TASK: transform
*/

#include<stdio.h>

int (**r_90)(int **,int);

int main() {

	FILE *fin = fopen("transform.in","r");
	FILE *fout = fopen("transform.out","w");
	int N;
	fscanf(fin,"%d",&N);
	
	char s[N][N];
	
	int i;
	for( i = 0; i< N; i++) {
		fscanf(fin,"%s",&s[i]);	
	}
	for ( i = 0; i < N; i++) {

		printf("%.*s\n",N,s[i]);
	}
	int** p= r_90(s,N);
	for ( i = 0; i < N; i++) {

                printf("%.*s\n",N,p[i]);
        }


exit(0);

}

int (**r_90)(int** s,int N) {
	char test[N][N];
	int i,j;
	for(i = 0; i <N; i++) {
		for( j = 0; j < N; j ++) {
			test[j][N-1 - i] = 0;
		}
	}
	
	return test;
}
	
