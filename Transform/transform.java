/*
ID: liudi192
LANG: JAVA
TASK: transform
*/

import java.util.*;
import java.io.*;

class transform {
	public static void main(String[] argv) throws IOException{
		
		BufferedReader f = new BufferedReader( new FileReader("transform.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int N = Integer.parseInt(st.nextToken());		
		String[] mat = new String[N];
		String[] res = new String[N];
		int i,j;
		//mat[0] = new String("this is test");
		for( i = 0; i < N; i ++ ) {
			mat[i] = new String(f.readLine());
		}
		for( i = 0; i < N; i ++) {
			res[i] = new String(f.readLine());
		}
		int flag = -1;


		int test = 1;
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[j].charAt(N - i - 1) != mat[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 1;
		


		test = 1; 
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[N - i - 1].charAt(N - j - 1) != mat[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 2;
		
		test = 1; 
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[N - j - 1].charAt(i) != mat[i].charAt(j))
				{
					test = 0;	
				}
			}
		}

		if (test == 1 && flag < 0)
			flag = 3;


		StringBuffer buffer;

		String[] rev = new String[N];
		for(i= 0; i< N; i ++)	{
			buffer = new StringBuffer(mat[i]);
			buffer.reverse();
			rev[i] = new String(buffer.toString());
		}

		test = 1;
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[i].charAt(j) != rev[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 4;



		test = 1;
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[j].charAt(N - i - 1) != rev[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 5;


		
		test = 1; 
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[N - i - 1].charAt(N - j - 1) != rev[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 5;
		
		test = 1; 
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[N - j - 1].charAt(i) != rev[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 5;
		
		test = 1; 
		for ( i = 0; i < N; i ++ ) 
		{
			for ( j = 0; j < N; j ++) 
			{
				if(res[i].charAt(j) != rev[i].charAt(j))
				{
					test = 0;	
				}
			}
		}
		if (test == 1 && flag < 0)
			flag = 6;
		
		if (flag < 0)
			flag = 7;
		out.println(flag);
		out.close();
		
		//Matrix origin = new Matrix()
		System.exit(0);

	}
}

