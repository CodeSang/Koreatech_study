package _1005_ACM크래프트;

import java.util.*;

public class Main {

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		int tc = sc.nextInt();

		while( tc -- >= 0){
			
			// number of buildings(v)	// number of rules(e)
			int n = sc.nextInt();		int k = sc.nextInt();
			
			int[] time = new int[n+1];
			for(int i = 1; i <= n; i++){
				time[i] = sc.nextInt();
			}
			
			ArrayList<Integer>[] g = new ArrayList[n+1];
			int ind[] = new int[n+1];
			Arrays.fill(ind,0);
			
			for(int i = 1; i <= n; i++){
				g[i] = new ArrayList<Integer>();
			}
			
			for(int i = 1; i <= k; i++){
				int v1 = sc.nextInt();
				int v2 = sc.nextInt();

				ind[v2]++;
				g[v1].add(v2);
				
			}
			// 건설해야할 건물
			int end = sc.nextInt();

			int[] timeC = new int[n+1];
			boolean[] check = new boolean[n+1];
			
			Arrays.fill(timeC,0);
			Arrays.fill(check,false);
			

			
			Queue<Integer> q = new LinkedList<Integer>();
			
			// ind == 0 인 것, 무엇이든.. 시작점에
			// 1부터 시작하는 것이 아님!!  timeC[1] = time[1]; 
			for(int i = 1; i <= n; i++){
				if( ind[i] == 0 ){
					q.add(i);
					timeC[i] = time[i];
				}
			}
			
			for(int kk = 0; kk < n; kk++){
				int x = q.remove();
				
				for( int y : g[x] ){
					
					ind[y] -= 1;
					
					if( timeC[y] < time[y] + timeC[x] ){
						timeC[y] = time[y] + timeC[x];
					}
					
					if( ind[y] == 0 ){
						q.add(y);
					}
					
				}
			}
			System.out.println(timeC[end]);
			
		}
	}
}