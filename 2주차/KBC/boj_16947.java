import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

//BOJ 16947 [서울 지하철 2호선]
//시간초과 발생
public class Main {
    private static int n;
    private static boolean[][] adjacencyMatrix;
    private static boolean[] isCycle;
    private static boolean[] isVisit;
    private static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        initialize(br);
        verifyIsCycleForAll();

        initializeDpArray();
        printDistance(sb);
    }

    public static void initialize(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());

        isCycle = new boolean[n + 1];
        isVisit = new boolean[n + 1];
        adjacencyMatrix = new boolean[n + 1][n + 1];
        dp = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = n;
        }

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);

            adjacencyMatrix[v1][v2] = true;
            adjacencyMatrix[v2][v1] = true;
        }
    }

    public static void verifyIsCycleForAll() {
        for (int i = 1; i <= n; i++) {
            boolean[][] matrix = new boolean[n + 1][n + 1];
            copyMatrix(adjacencyMatrix, matrix);
            verifyIsCycleForVertex(i, i, matrix);
        }
    }

    public static void copyMatrix(boolean[][] src, boolean[][] dest) {
        for (int i = 0; i < src.length; i++) {
            dest[i] = src[i].clone();
        }
    }

    public static void verifyIsCycleForVertex(int origin, int current, boolean[][] matrix) {
        if (current == origin && isVisit[current]) {
            markCycle();
            return;
        }
        for (int next = 1; next <= n; next++) {
            isVisit[current] = true;
            if (matrix[current][next]) {
                matrix[current][next] = false;
                matrix[next][current] = false;
                verifyIsCycleForVertex(origin, next, matrix);
            }
            isVisit[current] = false;
        }
    }

    public static void markCycle() {
        for (int i = 1; i <= n; i++) {
            isCycle[i] = isCycle[i] || isVisit[i];
        }
    }

    public static void initializeDpArray() {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (isCycle[i]) {
                dp[i] = 0;
                queue.add(i);
            }
        }
        calculateDpArray(queue);
    }

    public static void calculateDpArray(Queue<Integer> queue) {
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int next = 1; next <= n; next++) {
                if (adjacencyMatrix[current][next] && dp[next] > dp[current] + 1) {
                    dp[next] = dp[current] + 1;
                    queue.add(next);
                }
            }
        }
    }

    public static void printDistance(StringBuilder sb) {
        for (int i = 1; i <= n; i++) {
            sb.append(dp[i]).append(" ");
        }
        System.out.println(sb);
    }
}
