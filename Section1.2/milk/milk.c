/*
ID: liudi192
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>
main () {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
    int N, M;
    fscanf (fin, "%d %d", &N, &M);	/* the two input integers */
    int price[M];
    int amount[M];
    int i;
     for(i = 0; i < M; i ++) {
     	fscanf (fin, "%d %d", &price[i], &amount[i]);
     }

     int pre_min = -1;
     int min = 5000;
     int min_amount = 0;
     int total_price = 0;
     int total_amount = 0;
     
     int j = 0;
     int t,p;
     for(i = M - 1; i > 0 ; i--) {
        for(j = 0; j < i; j ++) {
            if (price[j] > price[j+1]){
                 t = price[j];
                 price[j] = price[j+ 1];
                 price[j+1] = t;

                 p = amount[j];
                 amount[j] = amount[j+ 1];
                 amount[j+1] = p;
             }

         }
     }

     while(total_amount < N)
     {
         if(total_amount + amount[i] < N){
                 total_price += amount[i]*price[i];
                 total_amount += amount[i];
         } else {
                 total_price += (N - total_amount)*price[i];
                 total_amount = N;
         }
         i++;
     }


    fprintf (fout, "%d\n", total_price);
    exit (0);

}
