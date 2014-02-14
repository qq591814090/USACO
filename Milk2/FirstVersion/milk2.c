/*
ID: liudi192
LANG: C
TASK: milk2
*/
#include<stdio.h>
main() {
	FILE *fin = fopen("milk2.in","r");
	FILE *fout = fopen("milk2.out","w");
	int N;
	fscanf(fin,"%d",&N);
	int times[N][2];
	int i,j;
	for(i = 0; i<N;i++) {
		fscanf(fin,"%d %d",&times[i][0],&times[i][1]);
	}
	int start,end,start_old, end_old,max = 0;
	
	
	for(i = 0;i<N;i++) {
		start = times[i][0];
		end = times[i][1];
		start_old = end;
		end_old = start;
		while ( start !=start_old && end != end_old) {
			start_old = start;
			end_old = end;
			for(j = 0; j < N;j++) {
				if( end <= times[j][1] && times[j][0] <= end) {
					end = times[j][1];
				}
				if( start <= times[j][1] && times[j][0] <=start) {
					start = times[j][0];
				}
			}
			
			
		}
		max = (end-start)>max ?(end-start):max;
	}
	
	int e , m = 0;
	int flag;				
	for ( i = 0; i < N; i ++ ) { 
		flag = 'T';
		start = times[i][1];
	//	for ( j = 0; j < N; j ++ ) {
//			if ( start < times[j][1] && times[j][0] < start ) {
//				flag = 'F';
//				break;
//			}
//		}
//		if ( flag == 'F') { continue;}
		e = times[0][0];
		for ( j  = 0; j < N; j++ ) {
			if ( start <= times[j][0]) {
				if (e < start) {
					e = times[j][0];
				} else {
					e = times[j][0] <  e? times[j][0] : e ;
				}
			}
			if ( start < times[j][1] && times[j][0] < start ) {
				e = start;
			}

		}
		
		
		m = m > (e - start)? m : e - start ;
		printf("%d\n",m);
	}
	
			
		
		








	printf("%d %d\n", max, m);
	fprintf(fout,"%d %d\n",max,m);
				


exit(0);
}
