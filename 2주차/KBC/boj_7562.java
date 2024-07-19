import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;


//BOJ 7562 [나이트의 이동]
public class Main {
    public static class Pos {
        public int x;
        public int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Pos target) {
            return this.x == target.x && this.y == target.y;
        }
    }

    private static Pos current;
    private static Pos target;
    private static int size;
    private static boolean[][] isVisit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            initialize(br);
            int count = bfs(current, target);
            System.out.println(count);
        }
    }

    public static void initialize(BufferedReader br) throws IOException {
        size = Integer.parseInt(br.readLine());
        isVisit = new boolean[size][size];
        String[] inputForCurrent = br.readLine().split(" ");
        String[] inputForTarget = br.readLine().split(" ");
        current = new Pos(Integer.parseInt(inputForCurrent[0]), Integer.parseInt(inputForCurrent[1]));
        target = new Pos(Integer.parseInt(inputForTarget[0]), Integer.parseInt(inputForTarget[1]));
    }

    public static int bfs(Pos current, Pos target) {
        Queue<Pos> queue = new LinkedList<>();
        queue.add(current);
        int count = 0;

        while (true) {
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                Pos poll = queue.poll();

                if (isOutOfRange(poll) || isVisit[poll.x][poll.y]) {
                    continue;
                }
                if (poll.equals(target)) {
                    return count;
                }
                queue.add(new Pos(poll.x - 2, poll.y - 1));
                queue.add(new Pos(poll.x - 2, poll.y + 1));
                queue.add(new Pos(poll.x - 1, poll.y - 2));
                queue.add(new Pos(poll.x + 1, poll.y - 2));
                queue.add(new Pos(poll.x + 2, poll.y - 1));
                queue.add(new Pos(poll.x + 2, poll.y + 1));
                queue.add(new Pos(poll.x - 1, poll.y + 2));
                queue.add(new Pos(poll.x + 1, poll.y + 2));

                isVisit[poll.x][poll.y] = true;
            }
            count++;
        }
    }

    public static boolean isOutOfRange(Pos poll) {
        return poll.x > size - 1 || poll.x < 0 || poll.y > size - 1 || poll.y < 0;
    }
}
