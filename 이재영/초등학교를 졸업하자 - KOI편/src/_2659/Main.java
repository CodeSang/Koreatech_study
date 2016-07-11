package _2659;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int[] a = {sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()};
		boolean[] b = new boolean[10000];
		
		
//		int ss = a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
		
		int tn = 10000;
	
		
		
		for(int i = 0; i<4; i++){
			int t = a[i%4]*1000 + a[(i+1)%4]*100 + a[(i+2)%4]*10 + a[(i+3)%4];
			if( t < tn ){
				tn = t;
			}
		}
//		System.out.println(tn);
		int z = tn;
		
		for(int i = 1; i < 10; i++){
			for(int j = 1; j < 10; j++){
				for(int m = 1; m < 10; m++){
					for(int n = 1; n < 10; n++){
						a[0] = i;
						a[1] = j;
						a[2] = m;
						a[3] = n;
						tn = 10000;
						for(int e = 0; e<4; e++){
							int t = a[e%4]*1000 + a[(e+1)%4]*100 + a[(e+2)%4]*10 + a[(e+3)%4];
							if( t < tn ){
								tn = t;
							}
						}
						b[tn] = true;
						
					}
				}
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < 10000; i++){
			
			if(b[i])
				cnt++;
			
			if(i == z )
				System.out.println(cnt);	
			
		}
		
		
	}

}
