package _1916_최소비용구하기;

import java.util.*;

class Edge{
	int to, cost;
	Edge(int to, int cost){
		this.to = to;
		this.cost = cost;
	}
}
public class Main {
	static final int INF = 1000000000;
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();		int m = sc.nextInt();
		
		ArrayList<Edge>[] g = new ArrayList[n+1];
		
		for(int i = 1; i <= n; i++){
			g[i] = new ArrayList<Edge>();
		}
		
		for(int i = 1; i <= m; i++){
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			int w = sc.nextInt();
			
			g[v1].add(new Edge(v2,w));
		}
		int start = sc.nextInt();
		int end = sc.nextInt();
		
		int[] dist = new int[n+1];
		boolean[] check = new boolean[n+1];
		
		Arrays.fill(dist,INF);
		Arrays.fill(check,false);
		
		dist[start] = 0;
		
		// 모든 정점 -1 번 반복.. ( n-1 )회.
		for(int k = 0; k < n -1; k++){
			int t = INF +1;
			int x = -1;
			
			// check가 되지 않았고, dist[i] 가 가장 작은 곳 찾는다.
			for(int i = 1; i <= n; i++){
				if( check[i] == false && t > dist[i] ){
					t = dist[i];
					x = i;
				}
			}
			check[x] = true;
			
			// 그 정점에서 가장 가중치가 작은 것으로 최신화
			for(Edge y : g[x]){
				if( dist[y.to] > dist[x] + y.cost ){
					dist[y.to] = dist[x] + y.cost;
				}
			}
		}
		System.out.println(dist[end]);
				
	}
}
