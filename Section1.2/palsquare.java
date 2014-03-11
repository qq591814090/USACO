/*
ID: lidui192
LANG: JAVA
TASK: palsquare
*/

import java.util.*;
import java.io.*;

public class palsquare{
	public static void main(String[] argv) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));

		int B = Integer.parseInt(f.readLine());

		int i;
		String num = new String("0123456789ABCDEFGHIJK");
		String origin, square;
		String ro, rs;
		int temp_o, temp_s;

		int flag = 0;
		for ( i = 1 ; i <= 300; i++) {
			origin = "";
			square = "";
			flag = 0;

			temp_o = i;
			temp_s = i*i;
			while(temp_o > 0){
				origin = num.charAt(temp_o%B ) + origin;
				temp_o = temp_o / B;
			}
			while(temp_s > 0){
				square = num.charAt(temp_s%B ) + square;
				temp_s = temp_s / B;
			}

			ro = new StringBuffer(origin).reverse().toString();
			rs = new StringBuffer(square).reverse().toString();
			if( rs.equals(square))
			{
				out.println(origin+" "+square);
			}
		}
		out.close();
		f.close();
	}
}
