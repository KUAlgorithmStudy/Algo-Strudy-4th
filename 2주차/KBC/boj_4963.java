import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//BOJ 4963 [섬의 개수]
public class Main {
    private static int[][] map;
    private static boolean[][] isVisit;
    private static int height;
    private static int width;
    private static final int LAND = 1;
    private static final int SEA = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String[] input = br.readLine().split(" ");
            width = Integer.parseInt(input[0]);
            height = Integer.parseInt(input[1]);
            if (width == 0 || height == 0) {
                break;
            }

            initialize(br);

            int numOfLands = countLand();
            System.out.println(numOfLands);
        }

    }

    public static void initialize(BufferedReader br) throws IOException {
        map = new int[height][width];
        isVisit = new boolean[height][width];

        for (int h = 0; h < height; h++) {
            String[] input = br.readLine().split(" ");
            for (int w = 0; w < width; w++) {
                map[h][w] = Integer.parseInt(input[w]);
            }
        }
    }

    public static int countLand() {
        int count = 0;
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                if (!isVisit[h][w] && map[h][w] == LAND) {
                    dfs(h, w);
                    count++;
                }
            }
        }
        return count;
    }

    public static void dfs(int h, int w) {
        if (isOutOfIndex(h, w) || isVisit[h][w] || map[h][w] == SEA) {
            return;
        }

        isVisit[h][w] = true;

        dfs(h + 1, w - 1);
        dfs(h + 1, w);
        dfs(h + 1, w + 1);
        dfs(h, w - 1);
        dfs(h, w + 1);
        dfs(h - 1, w - 1);
        dfs(h - 1, w);
        dfs(h - 1, w + 1);
    }

    public static boolean isOutOfIndex(int h, int w) {
        return h > height - 1 || h < 0 || w > width - 1 || w < 0;
    }
}
