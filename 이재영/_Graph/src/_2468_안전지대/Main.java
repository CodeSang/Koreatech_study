package _2468_안전지대;

import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int[][] g;
	static boolean[][] c;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };

	public static void main(String args[]) throws FileNotFoundException{

		Scanner sc = new Scanner(System.in);
//		Scanner sc = new Scanner(new FileInputStream("src/_2468_안전지대/Input.txt"));

		n = sc.nextInt();
		g = new int[n+1][n+1];
		c = new boolean[n+1][n+1];
		int max = 0; 
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int v = sc.nextInt();
				g[i][j] = v;
				if( v > max ){
					max = v;
				}
			}
		}
		
		
		int ans = 0;
		for(int k = 1; k <= max; k++){
			
			for(int i = 0; i < n; i++){
				Arrays.fill(c[i], true);
			}
			erase(k);
			int cnt = 0;
			
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if( c[i][j] ){
						cnt ++;
						bfs(i, j);
					}
				}
			}
			
			if( cnt > ans ){
				ans = cnt;
			}
			
			
		}
		System.out.println(ans);


	}

	static void erase(int num){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if( g[i][j] <= num ){
					c[i][j] = false; 
				}
			}
		}
	}

	static void bfs(int a, int b){

		Queue<Integer> q = new LinkedList<Integer>();
		q.add(a);	q.add(b);

		while( !q.isEmpty() ){
			int x = q.remove();
			int y = q.remove();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];

				if( check(nx, ny) && c[nx][ny] ){
					q.add(nx);	q.add(ny);
					c[nx][ny] = false; 
				}
			}
		}
	}
	static boolean check(int x,int y){

		if( x >= 0 && x < n && y >= 0 && y < n )
			return true;
		else
			return false;
	}
}
