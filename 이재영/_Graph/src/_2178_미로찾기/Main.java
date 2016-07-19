package _2178_미로찾기;

import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int m;
	static int[][] g;
	static int[][] dist;
	
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };

	public static void main(String args[]) throws FileNotFoundException{

//		Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new FileInputStream("src/_2178_미로찾기/input.txt"));

		n = sc.nextInt();
		m = sc.nextInt();
		g = new int[n+1][m+1];
		dist = new int[n+1][m+1];
		
		for(int i = 1; i <= n; i++){
			String t = sc.next();
			for(int j = 1; j <= m; j++){
				g[i][j] = Integer.parseInt((t.charAt(j - 1)+""));
			}
		}
		
		for(int[] a : dist){
			Arrays.fill(a, -1);
		}
		
		bfs(1,1);
		
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= m; j++)
//				System.out.print(dist[i][j]+" ");
//			System.out.println();
//		}
		
		System.out.println(dist[n][m]);

	}

	static void bfs(int a, int b){

		Queue<Integer> q = new LinkedList<Integer>();
		q.add(a);	q.add(b);
		dist[a][b] = 1;
		
		while( !q.isEmpty() ){
			int x = q.remove();
			int y = q.remove();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				// 범위를 벗어나지 않고, 방문하지 않았으며, 이어져 있는 곳.
				if( check(nx, ny) && dist[nx][ny] == -1 && g[nx][ny] == 1 ){
					q.add(nx);	q.add(ny);
					dist[nx][ny] = dist[x][y] + 1; 
				}
			}
		}
	}
	static boolean check(int x,int y){

		if( x >= 1 && x <= n && y >= 1 && y <= m )
			return true;
		else
			return false;
	}
}
