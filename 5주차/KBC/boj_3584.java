import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

//BOJ 3584 [가장 가까운 공통 조상]
public class Main {
    public static class Graph {
        List<Integer> adjust;

        public Graph(int n) {
            adjust = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                adjust.add(-1);
            }
        }

        public void setParent(int child, int parent) {
            adjust.set(child, parent);
        }

        public Integer getParent(int node) {
            return adjust.get(node);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for (int nCase = 0; nCase < N; nCase++) {
            int n = Integer.parseInt(br.readLine());
            Graph graph = new Graph(n);

            for (int i = 0; i < n - 1; i++) {
                String[] input = br.readLine().split(" ");
                int parent = Integer.parseInt(input[0]);
                int child = Integer.parseInt(input[1]);
                graph.setParent(child, parent);
            }

            String[] input = br.readLine().split(" ");
            int node1 = Integer.parseInt(input[0]);
            int node2 = Integer.parseInt(input[1]);

            List<Integer> log = new ArrayList<>();
            int parent = node1;
            log.add(parent);
            while (parent != -1) {
                parent = graph.getParent(parent);
                log.add(parent);
            }

            parent = node2;
            while (!log.contains(parent)) {
                parent = graph.getParent(parent);
            }
            System.out.println(parent);
        }

    }
}
