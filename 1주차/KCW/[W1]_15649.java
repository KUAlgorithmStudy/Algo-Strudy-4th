package W1;
import java.util.Scanner;

public class BOJ_15649 {
	static int N, M;
	static int visited[] = new int[9];
	static int arr[] = new int[9];
	static void print() {
		for(int i = 0; i<M; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
	static void select(int depth) {
		if(depth == M) {
			print();
			return;
		}
		for(int i = 1; i <= N; i++) {
			if(visited[i] > 0)
				continue;
			visited[i] = 1;
			arr[depth] = i;
			select(depth+1);
			visited[i] = 0;			
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		select(0);
	}

}
