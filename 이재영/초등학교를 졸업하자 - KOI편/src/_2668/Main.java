package _2668;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int[][] a = new int[101][101];
		
		for(int i = 1; i <= n; i++){
			a[i][sc.nextInt()] ++;
		}
		/*
		for(int i = 1; i <= n; i++){
			for(int j = 1; j<= n; j++){
				System.out.print(a[i][j] +" ");
			}
			System.out.println();
		}
		*/
		int cnt = 0;
		ArrayList<Integer> nn = new ArrayList<Integer>();
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j<= i; j++){
				
				if( a[i][j] == 1 && a[j][i] == 1 ){
					
					if( i == j ){
						cnt++;
						nn.add(i);
					}else{
						cnt+=2;
						nn.add(i);
						nn.add(j);
					}
				}
				
			}
		}
		System.out.println(cnt);
		Collections.sort(nn);
		for(int m : nn){
			System.out.println(m);
		}
		
	}

}
