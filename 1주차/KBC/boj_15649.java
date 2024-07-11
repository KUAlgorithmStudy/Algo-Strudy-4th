import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//BOJ 15649 [N과 M(1)]
public class Main {
    private static int[] arr;
    private static boolean[] isVisit;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        arr = new int[M];
        isVisit = new boolean[N];
        dfs(N,M,0);
    }
    public static void dfs(int N, int M, int depth) {
        if(depth == M) {
            for(int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
            return;
        }
        for(int i=0; i<N; i++) {
            if (!isVisit[i]) {
                isVisit[i] = true;
                arr[depth] =i+1;
                dfs(N,M,depth+1);

                isVisit[i] = false;
            }
        }
    }
}
