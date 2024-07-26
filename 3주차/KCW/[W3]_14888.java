package W3;
import java.io.*;
import java.util.*;
public class W3_14888 {
	static int N, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
	static int A[], operators[] = new int[4];
	
	static int calcNum(int a, int b, int op) {
		int result = 0;
		if(op == 0) result = a+b;
		else if(op == 1) result = a-b;
		else if(op == 2) result = a*b;
		else if(op == 3) result = (int)a/b;
		return result;
	}
	static void dfs(int depth, int calculated) {

		if(depth == N) {
			max = max < calculated?calculated:max;
			min = min > calculated?calculated:min;
			return;
		}
		for(int i = 0; i<4; i++) {
			if(operators[i] == 0) continue;
			int cal =  calcNum(calculated,A[depth],i);
			operators[i]--;
			dfs(depth+1,cal);
			operators[i]++;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine().trim());
		A = new int[N];
		st = new StringTokenizer(br.readLine().trim());
		for(int i = 0; i<N; i++) {
			A[i] = Integer.parseInt(st.nextToken());			
		}
		st = new StringTokenizer(br.readLine().trim());
		for(int i = 0; i<4; i++) {
			operators[i] = Integer.parseInt(st.nextToken());			
		}
		
		dfs(1, A[0]);
		
		System.out.println(max);
		System.out.println(min);
	}

}
