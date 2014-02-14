/*
ID: liudi192
LANG: C
TASK: milk2
*/

#include<stdio.h>

typedef struct t t;
struct t
{
	int op;
	int ed;
}

main() {
	FILE *fin = fopen("milk2.in","r");
	FILE *fout = fopen("milk2.out","w");
	int N;
	
	fscanf(fin,"%d",&N);
	
	t list[N];

	int i, j;
	t temp;
	for ( i = 0; i < N; i ++ ) {
                fscanf(fin,"%d %d",&list[i].op,&list[i].ed);
        }


	for ( i = 0; i < N; i++) {
		for ( j = N -1; j > i; j --) {
			if ( list[j-1].op > list[j].op ) {
				temp.op = list[j].op;
				temp.ed = list[j].ed;
				list[j].op = list[j-1].op;
				list[j].ed = list[j-1].ed;
				list[j - 1].op = temp.op;
				list[j -1 ].ed = temp.ed;
			}
		}

	}
	
	int start, end, mw;
	mw = list[0].ed - list[0].op;

	for ( i = 0; i < N; i ++ ) {
		start = list[i].op;
		end = list[i].ed;
		for ( j = i + 1; j < N; j ++ ) {
			if ( end <= list[j].ed && end >= list[j].op ) {
				end = list[j].ed;
			}
		}
		
		mw = mw > end - start? mw: end - start;  
	}	
//	printf("%d\n", mw);
	int flag = 'T';
	int mnw = 0;
	for ( i = 0; i < N; i ++ ) {
		flag = 'T';
		start = list[i].ed;
		end =list[i].ed;
		for ( j =  0; j < N; j++ ) {
			if (list[i].ed < list[j].ed &&list[i].ed >= list[j].op ) {
				flag = 'F';
				break;	
			}	
		}
		if ( 'F' == flag ) { 
			continue;
		} else {
			for ( j = i + 1; j < N; j ++ ) {
				if (list[j].op >= list[i].ed) {
					start = list[i].ed;
					end = list[j].op;
				}
				break;
			}
		}
		
		mnw = mnw > end - start? mnw : end - start;
		
		printf("%d\n", mnw);
				
	}	
	
	fprintf(fout,"%d %d\n", mw, mnw);	
exit(0);

}
