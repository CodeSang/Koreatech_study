package _2669;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception{
		
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		
		int[] a = new int[16+1];
		boolean[][] b = new boolean[101][101];
		int cnt = 0;
		
		for(int i = 1; i<= 16;i++){
	
			
			a[i] = sc.nextInt();
		}
		
		for(int i = 1; i <= 13; i+=4){
	
			
			for(int j = a[i]; j < a[i+2]; j++ ){
				for(int k = a[i+1]; k<a[i+3]; k++){
//					if( b[j][k] )
//						continue;
					b[j][k] = true;
//					cnt++;
				}
				
			}
		}
		
		for(int i = 0; i<= 10; i++){
			for(int j = 0; j<= 10;j++){
				if(b[i][j]){
					System.out.print(1+" ");
					cnt++;
				}
				else
					System.out.print(0+" ");
			}
			System.out.println();
			
		}
		
		
		
		System.out.println(cnt);
	}
}
