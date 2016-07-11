package _2512;

import java.util.*;
import java.io.*;

public class Main {

	
	static int n;
	static long total;
	static int[] a;

	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(new FileInputStream("src/_2512/input.txt"));
//		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		a = new int[n];
		

		for(int i = 0; i<n; i++){
			a[i] = sc.nextInt();
	
		}
		total = sc.nextInt();
		
		int avg = (int) (total / n);
		
		long max = 0;
			
		for(int i = avg; ; i++){
			long t = cal(i);
			if( t > total ){
				System.out.println(i);
				break;
			}
			if( t > max ){
				max = t;
			}
			
		}

	}
	static long cal(int num){

		long res = 0;
		
		for(int i = 0; i < n; i++){
			if( a[i] >= num ){
				res += num;
			}
			else{
				res += a[i];
			}
		}
		return res;
	}

}
