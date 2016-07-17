package _9663_NQueen;

import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static boolean[][] m;
	static boolean[][] b;
	static int cnt = 0;

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();

		m = new boolean[n][n];
		b = new boolean[n][n];

		for(int i = 0; i < n; i++){
			Arrays.fill(m[i], true);
		}
		int q = 0;
		int aa = 0;
		
		go(0,0,0);
		System.out.println(cnt);


		//		System.out.println(aa);

		m[0][0] = true;

		//		for(int i = 0; i < n; i++){
		//			for(int j = 0; j < n; j++){
		int j = 2;
		int i = 2;
		if( m[i][j] == true ) {
			for(int k = 0; k < n; k++){
				m[k][j] = false;
				m[i][k] = false;
			}
			for(int k = 0; k < n; k++){
				for(int l = 0; l < n; l++){
					if( k + l == i+ j)
						m[k][l] = false; 

					if( l - k == j - i)
						m[k][l] = false; 

				}
			}
		}
		//			}
	//		}

		for(int f = 0 ; f<n; f++){
			for(int v = 0; v <n; v++){
				if( m[f][v] )
					System.out.print(1+ " ");
				else
					System.out.print(0+ " ");
			}
			System.out.println();
		}

	}



	static void go(int x,int y,int q){


		
		if( m[x][y] == true ) {
			q++;
			
			if( q == n ){
				cnt++;
				return ;
			}
						
			b = m;
			
			// q 놓은 것에 대해 맵 정보 반영
			for(int k = 0; k<n; k++){
				m[k][y] = false;
				m[x][k] = false;
			}
			for(int k = 0; k <n; k++){
				for(int l = 0; l < n; l++){
					if( k + l == x + y)
						m[k][l] = false; 

					if( l - k == y - x)
						m[k][l] = false; 

				}
			}
			
			 
			if( x < n - 2 ){
				go(x+1,y,q);
			}else if( y < n-2 ){
				go(0,y+1,q);
			}
			m = b;
		}

	}


}




