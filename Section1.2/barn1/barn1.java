/*
ID: liudi192
LANG: JAVA
TASK: barn1
*/

import java.util.*;
import java.io.*;


public class barn1 {
	public static void main(String[] argv) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("barn1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));

		Scanner s = new Scanner(f.readLine());
		int M = s.nextInt();
		int S = s.nextInt();
		int C = s.nextInt();
			//System.out.println(M+" " + S+" "+ C);
		int i,j,k ;
		int[] barn_num = new int[C + 1];
		int[] barn_flag = new int[S + 1];

		for(i = 1; i < S + 1; i ++) {
			barn_flag[i] = 0;
			//System.out.println(barn_num[i]);
		}
		for(i = 1; i < C + 1; i ++) {
			int temp = Integer.parseInt(f.readLine());
			barn_flag[temp] = 1;
			barn_num[i] = temp;
			 //System.out.println(barn_num[i]);
		}
		for(i = C ; i > 0; i --) {
			for(j = 1; j < i; j ++){
				if(barn_num[j]>barn_num[j+1]){
					k = barn_num[j];
					barn_num[j] = barn_num[j+1];
					barn_num[j+1]= k; 
				}
			}
		}

		int[] flag = new int[S + 1];
		for(i = 1; i < S + 1; i ++) {
			if((i < barn_num[1])||(i > barn_num[C]))
				flag[i] = 0;
			else
				flag[i] = 1;
		}


		int last_stall, length_of_gap;
		int max_last_stall , max_length_of_gap;
		for(i = 1; i < M; i ++) {
			length_of_gap = 0;
			max_length_of_gap = 0;
			last_stall = barn_num[1];
			max_last_stall = barn_num[1];
			for(j = barn_num[1]; j <= barn_num[C]; j++) {
				if(barn_flag[j] == 1) {
					length_of_gap = 0;
					last_stall = j;
				} else {
					length_of_gap++;
				}
				if(length_of_gap > max_length_of_gap) {
						max_length_of_gap = length_of_gap;
						max_last_stall = last_stall;
				}
				// System.out.println("this is length_of_gap: "+ length_of_gap+"  and this is last_stall:  "+ last_stall);
				// System.out.println("this is maxlength_of_gap: "+ max_length_of_gap+"  and this is max_last_stall:  "+ max_last_stall);
			}
			// for(j = 1; j < S + 1; j++){
			// 	if(barn_flag[j] == 1) {

			// 		System.out.println("."+j);
			// 	}
			// }



			//System.out.println(max_length_of_gap+" " + max_last_stall);
			for(j = 0; j < max_length_of_gap; j ++) {
				flag[max_last_stall + j + 1] = 0;

				barn_flag[max_last_stall + j + 1] = 1;
			}

			for(j = 1; j < S + 1; j++){
				if(flag[j] == 1) {

					// System.out.println(j);
				}
			}
		}

		int counter= 0;

		for(i = 1; i < S + 1; i++){
			if(flag[i] == 1) {
				counter++;
				// System.out.println(i);
			}
		}
		
		out.println(counter);
		f.close();
		out.close();


	}
}
