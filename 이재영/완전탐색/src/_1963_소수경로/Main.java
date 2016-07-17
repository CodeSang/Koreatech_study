package _1963_소수경로;

import java.io.*;
import java.util.*;

public class Main {

	static boolean isPrime[];


	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);


		int tc = sc.nextInt();
		isPrime = new boolean[10001];
		Arrays.fill(isPrime, true);

		makeIsPrime();

		for(int i = 0; i < 1000; i++){
			isPrime[i] = false;	
		}


		while( tc-- > 0 ){
			int start = sc.nextInt();
			int end = sc.nextInt();

			Queue<Integer> q = new LinkedList<Integer>();
			boolean c[] = new boolean[10001];
			int dist[] = new int[10001];
			int ans = 54321;

			dist[start] = 0;
			c[start] = true;
			q.add(start);




			while(!q.isEmpty()){
				int now = q.remove();

				for(int i = 0; i < 4; i++){
					for(int j = 0; j < 10; j++){


						int next = ex(now,i,j);



						if( isPrime[next] && !c[next] ){
							q.add(next);
							c[next] = true;
							dist[next] = dist[now] + 1;


						}					
						if( next == end ){
							ans = dist[next];
							q.clear();
							Arrays.fill(c, true);
							break;
						}


					}
				}

			}

			if( ans == 54321 )
				System.out.println("Impossible");
			else
				System.out.println(ans);
		}

	}
	// i         0 1 2 3
	// j         0 1 2 3 4 5 6 7 8 9
	static int ex(Integer now, int i, int j) {


		StringBuilder res = new StringBuilder(now.toString());
		char e = Character.forDigit(j, 10);
		res.setCharAt(i, e);

		return Integer.parseInt(res.toString());

	}

	static void makeIsPrime(){

		isPrime[0] = false;
		isPrime[1] = false;

		for(int i = 2; i*i < 10000; i++){
			if( isPrime[i] ){
				for(int j = i+i; j < 10000; j += i){
					isPrime[j] = false;
				}
			}
		}

	}

}
