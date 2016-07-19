package _1922_네트워크연결;

import java.io.*;
import java.util.*;

class Edge{
	public int start;
	public int end;
	public int cost;
	
	public Edge(){
		this(0,0,0);
	}
	public Edge(int start, int end, int cost){
		this.start = start;
		this.end = end;
		this.cost = cost;
	}
}

public class Main {
	
	static class Compare implements Comparator<Edge>{
		public int compare(Edge one, Edge two){
			return Integer.compare(one.cost, two.cost);
		}

		
	}
	
	
	static int vCnt;
	static int eCnt;
	static ArrayList<Edge>[] g;
	static boolean[] check;
	static int[] dist;
 	
	static final int INF = 1000000;
	
	public static void main(String args[]) throws FileNotFoundException{

		Scanner sc = new Scanner(System.in);
		
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
			
			g[v1].add(new Edge(v1,v2,w));
			g[v2].add(new Edge(v2,v1,w)); 
		}
		Compare cmp = new Compare();
		
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(1,cmp);
		check[1] = true;
		for( Edge e : g[1]){
			pq.add(e);
		}
		int ans = 0;
		// 모든 정점
		for(int i = 1; i <= vCnt-1; i++){
			Edge e = new Edge();
			
			while(!pq.isEmpty()){
				e = pq.poll();
				if( check[e.end] == false ){
					break;
				}
			}
			check[e.end] = true;
			ans += e.cost;
			for( Edge ee : g[e.end]){
				pq.add(ee);
			}
		}
		System.out.println(ans);
	}
}

