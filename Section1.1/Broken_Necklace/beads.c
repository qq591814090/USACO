/*
ID: liudi192
LANG: C
TASK: beads
*/
#include <stdio.h>
main() {
	FILE *fin = fopen("beads.in","r");
	FILE *fout = fopen("beads.out","w");
	int N;
	fscanf(fin,"%d",&N);
	char beads[352];	
	fscanf(fin,"%s",&beads);
	char right,left;
	int i,j;
	int max = 0;
	int count_right,count_left;
	for( i = 0; i <= N; i++) {
//		printf("%d\n",i);
		right = 'w';
		left = 'w';
		count_left = 0;
		count_right = 0;
		for( j = 0; j < N; j++) {
//			printf("%c",beads[(i+j+1)%N]);
			if( beads[(i+j+1)%N] == 'w') {
			} else {
				if ( right =='w') {
					right = beads[(i+j+1)%N];
				} else {
					if (right != beads[(i+j+1)%N]) {
						break;
					}
				}
			
			}
			count_right++;
		}
//		printf(" %d  ",count_right);
                for( j = 0; j < N-count_right; j++) {
//			printf("%c",beads[(i-j+N)%N]);
                        if( beads[(i-j+N)%N] == 'w') {                
                        } else {
                                if ( left =='w') {
                                        left = beads[(i-j+N)%N];
                                } else {
                                        if (left != beads[(i-j+N)%N]) {
                                                break;
                                        }       
                                }
                        }
                	count_left++;
		}
	
		

		max = count_right+count_left > max ? count_right+count_left:max;

	}


	fprintf(fout,"%d\n",max);
	exit(0);
}

			
						
