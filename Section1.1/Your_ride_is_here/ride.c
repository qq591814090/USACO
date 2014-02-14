/*
ID: your_id_here
LANG: C
TASK: ride
*/
#include <stdio.h>
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char line_1[8];
    char line_2[8];
    //fgets(line_1,6,fin);
    //fgets(line_2,6,fin);
    fscanf (fin, "%s", &line_1);	/* the two input integers */
    fscanf (fin, "%s", &line_2);
    //fprintf(fout, "%s",line_1);
   /* char c;
    c = fgetc(fin);
    if (EOF == c) {
	exit(0);
    }
	printf("%d",c);
	printf ("%s\n", line_1);
    c = fgetc(fin);
	printf("%d",EOF);
    if (fgetc(fin) == EOF) {
	exit(0);
    }
	
        printf ("%s\n", line_2);
    
     //printf("%d\n",strlen(line_1));
    //char a = 'a';
*/
    int num_1 = 1, num_2 = 1;
    int i;
    

    for ( i = 0; i < strlen(line_1) ; i++) {
        num_1 *= (line_1[i] - 'A' +1);
    }
    for ( i = 0 ; i < strlen(line_2); i++) {
            num_2 *= (line_2[i] - 'A' +1);
    }
    if ( num_1 % 47 == num_2 % 47) {

	    fprintf(fout,"GO\n");

    } else
    {
	fprintf(fout,"STAY\n");
    }
    exit (0);
}
