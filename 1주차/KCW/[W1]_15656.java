package W1;
import java.util.*;
import java.io.*;

public class W1_15656 {
	static int N, M;
	static int arr[], printArr[];
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[N];
		printArr = new int[M];
		
		for(int i = 0; i<N; i++)
			arr[i] = sc.nextInt();
		sc.close();
		
		Arrays.sort(arr);
		
		dfs(0);
		
		System.out.println(sb);
	}
	static void dfs(int depth) {
		if(depth == M) {
			for(int i = 0; i<M; i++) {
				sb.append(printArr[i]+" ");
			}
			sb.append("\n");
			return;
		}
		
		for(int i = 0; i<N; i++) {
			printArr[depth] = arr[i];
			dfs(depth + 1);
		}
	}

}
