import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

//BOJ 2210 [숫자판 점프]
public class Main {
    private static final int SIZE = 5;
    private static final int LENGTH_OF_RESULT = 6;
    private static final Integer[] arr = new Integer[LENGTH_OF_RESULT];
    private static final HashSet<String> results = new HashSet<>();
    private static int[][] map;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        initialize(br);
        calculateResults();
        System.out.println(results.size());
    }

    public static void initialize(BufferedReader br) throws IOException {
        map = new int[SIZE][SIZE];
        for (int h = 0; h < SIZE; h++) {
            String[] input = br.readLine().split(" ");
            for (int w = 0; w < SIZE; w++) {
                map[h][w] = Integer.parseInt(input[w]);
            }
        }
    }

    public static void calculateResults() {
        for (int h = 0; h < SIZE; h++) {
            for (int w = 0; w < SIZE; w++) {
                dfs(h, w, 0);
            }
        }
    }

    public static void dfs(int h, int w, int depth) {
        if (isOutOfRange(h, w))
            return;
        if (depth == LENGTH_OF_RESULT) {
            results.add(Arrays.toString(arr));
            return;
        }

        arr[depth] = map[h][w];
        dfs(h + 1, w, depth + 1);
        dfs(h - 1, w, depth + 1);
        dfs(h, w - 1, depth + 1);
        dfs(h, w + 1, depth + 1);
    }

    public static boolean isOutOfRange(int h, int w) {
        return h < 0 || h > SIZE - 1 || w < 0 || w > SIZE - 1;
    }
}
