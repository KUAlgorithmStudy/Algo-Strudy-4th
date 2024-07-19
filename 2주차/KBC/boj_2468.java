import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Math.max;
import static java.lang.Math.min;


//BOJ 2468 [안전영역]
public class Main {
    private static int n;
    private static int[][] heights;
    private static boolean[][] isVisit;
    private static int waterLevel;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        heights = new int[n][n];

        int maxHeight = 0;
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int k = 0; k < n; k++) {
                heights[i][k] = Integer.parseInt(input[k]);
                maxHeight = max(maxHeight, heights[i][k]);
            }
        }

        int result = 0;
        for (waterLevel = 0; waterLevel < maxHeight; waterLevel++) {
            isVisit = new boolean[n][n];
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (!isVisit[i][k] && heights[i][k] > waterLevel) {
                        dfs(i, k);
                        count++;
                    }
                }
            }
            result = max(result, count);
        }
        System.out.println(result);
    }

    public static void dfs(int i, int k) {
        if (!isVisit[i][k] && heights[i][k] > waterLevel) {
            isVisit[i][k] = true;
            dfs(i, min(n - 1, k + 1));
            dfs(i, max(k - 1, 0));
            dfs(min(n - 1, i + 1), k);
            dfs(max(i - 1, 0), k);
        }
    }
}
