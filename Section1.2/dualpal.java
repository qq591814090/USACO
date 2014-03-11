/*
ID: lidui192
LANG: JAVA
TASK: dualpal
*/

import java.util.*;
import java.io.*;

public class dualpal{
	public static void main(String[] argv) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("dualpal.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));

		String line = f.readLine();
		Scanner scan = new Scanner(line);
		int N = scan.nextInt();
		int S = scan.nextInt();

		int number_counter =0;
		int counter_bases =0;
		String num = new String("0123456789");
		String origin, square;
		String ro, rs;
		int temp_o, temp_s;
		int i, j = S;
		int flag = 0;

		while(number_counter < N){
			counter_bases = 0;
			j++;			
			for ( i = 2; i <= 10; i++){
				origin = "";
				temp_o = j;
				while(temp_o > 0){
					origin = num.charAt(temp_o% i ) + origin;
					temp_o = temp_o /  i;
				}
				ro = new StringBuffer(origin).reverse().toString();
				if( ro.equals(origin))
				{
					counter_bases ++;
				}

				if(counter_bases > 1)
				{
					out.println(j);
					number_counter ++;
					break;
				}
			}
		}

		out.close();
		f.close();
		
	}
}
