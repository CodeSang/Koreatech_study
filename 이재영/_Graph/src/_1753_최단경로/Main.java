package _1753_최단경로;

import java.io.*;
import java.util.*;

class Edge{
	int to, cost;
	Edge(int to, int cost){
		this.to = to;
		this.cost = cost;
	}
}

public class Main {

	static int vCnt;
	static int eCnt;
	static ArrayList<Edge>[] g;
	static boolean[] check;
	static int[] dist;
 	
	static final int INF = 1000000;
	
	public static void main(String args[]) throws FileNotFoundException{

		Scanner sc = new Scanner(System.in);
//		Scanner sc = new Scanner(new FileInputStream("src/_1753_미로찾기/input.txt"));
		
		vCnt = sc.nextInt();		eCnt = sc.nextInt();
		
		
		g = new ArrayList[vCnt+1];
		check = new boolean[vCnt+1];
		dist = new int[vCnt+1];
		
		for(ArrayList m : g){
			m = new ArrayList<Edge>();
		}
		
		for(int i = 1; i <= vCnt; i++){
			g[i] = new ArrayList<Edge>(); 
		}
		
		for(int i = 1; i <= eCnt; i++){
			int v1 = sc.nextInt();		int v2 = sc.nextInt();
			int w = sc.nextInt();
			
			g[v1].add(new Edge(v2, w));
		}
		
		// start Vertex.
		int start = sc.nextInt();
		int end = sc.nextInt();
				
		Arrays.fill(dist, INF);
		Arrays.fill(check, false);
		
		dist[start] = 0;
		
		for(int i = 0; i < vCnt-1; i++){
			
			eCnt = INF + 1;
			int x = -1;
			for(int j = 1; j <= vCnt; j++){
				if( check[j] == false && eCnt > dist[j] ){
					eCnt = dist[j];
					x = j;
				}
			}
			check[x] = true;
			
			for( Edge y : g[x] ){
				if( dist[y.to] > dist[x] + y.cost ){
					dist[y.to] = dist[x] + y.cost;
				}
			}
			
		
		}
		
		System.out.println(dist[end]);
		
	}

}