package _2660_»∏¿ÂªÃ±‚;

import java.util.*;
import java.io.*;
 
public class Main {
 
    static ArrayList<Integer>[] g;
    static int c[];
     
    public static void main(String[] args) throws FileNotFoundException {
 
//      Scanner sc = new Scanner(new FileInputStream("src/_2660_»∏¿ÂªÃ±‚/input.txt"));
        Scanner sc = new Scanner(System.in);
         
        int n = sc.nextInt();
        g = new ArrayList[n+1];
        c = new int[n+1];
        int[] res = new int[n+1];
        int s = Integer.MAX_VALUE;
        int ss = 0;
        String r ="";
         
        for(int i = 1; i <= n; i++)
            g[i] = new ArrayList<Integer>(); 
         
         
        int v1;
        int v2;
         
        while(true){
            v1 = sc.nextInt();
            v2 = sc.nextInt();
         
            if( v1 == -1 && v2 == -1 )
                break;
             
            g[v1].add(v2);
            g[v2].add(v1);
        }
         
        for(int i = 1; i <= n; i++){
            Arrays.fill(c, 0);
            res[i] = bfs(i);
             
            if( s > res[i] ){
                s = res[i]; 
            }
        }
         
        for(int i = 1; i<=n; i++){
            if( res[i] == s ){
                ss++;
                r += i+" ";
            }
        }
        System.out.println(s+ " "+ss);
        System.out.println(r.trim());
    }
     
    static int bfs(int start){
         
        c[start] = 1;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        int idx = 1;
         
        while(!q.isEmpty()){
            int a = q.remove();
             
            for( int m : g[a] ){
                 
                if( c[m] == 0 ){
                    q.add(m);
                    c[m] = c[a]+1;
//                  idx = c[m];
                    if( idx < c[m] )
                        idx = c[m];
                }
                 
            }
        }
        return idx-1;
    }
 
}