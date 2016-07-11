package _2303;

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(new FileInputStream("src/_2303/input.txt"));
//		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int card[][] = new int[n+1][5];
		int res[] = new int[n+1];
		int ans = 0;
		int max = -192;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j<5; j++ ){
				card[i][j] = sc.nextInt();
			}
		}
		
		for(int i = 1; i <= n; i++){
			res[i] = max(card[i]);
//			System.out.println(res[i]);
			
			if( max <= res[i] ){
				max = res[i];
				ans = i;
			}
		}
		System.out.println(ans);
		
	}
	static int max(int[] nums){
		int res = 0;
		
		for(int i = 0; i < 5; i++){
			for(int j = i+1; j < 5; j++){
				for(int k = j+1; k < 5; k++){
					
					int t = ( nums[i] + nums[j] + nums[k] )%10;
					if( t > res ){
						res = t;
					}
				}
			}
		}
		
		return res;
	}

}
