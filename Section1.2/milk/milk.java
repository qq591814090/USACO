/*
ID: liudi192
LANG: JAVA
TASK: milk
*/

import java.io.*;
import java.util.*;

public class milk{

        public static void main(String [] argv) throws IOException{
                BufferedReader f = new BufferedReader(new FileReader("milk.in"));
                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));

                Scanner s = new Scanner(f.readLine());
                int N = s.nextInt();
                int M = s.nextInt();
                int[] price = new int[M];
                int[] amount = new int[M];
                String nextline;
                int i = 0;
                while((nextline = f.readLine())!=null){
                        s = new Scanner(nextline);
                        price[i] = s.nextInt();
                        amount[i] = s.nextInt();
                        i++;
                }


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
            i = 0;
            int total = 0;
            int total_amount = 0;
            while(total_amount < N)
            {
                if(total_amount + amount[i] < N){
                        total += amount[i]*price[i];
                        total_amount += amount[i];
                } else {
                        total += (N - total_amount)*price[i];
                        total_amount = N;
                }
                i++;
            }
            out.println(total);
            out.close();
            f.close();
        }
}
                                           
