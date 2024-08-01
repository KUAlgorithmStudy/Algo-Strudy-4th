import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//BOJ 1967 [트리의 지름]
public class Main {
    private static Graph weightedGraph;
    private static int maxWeight;
    private static boolean[] isVisited;

    public static class Edge {
        int targetNode;
        int weight;

        public Edge(int target, int weight) {
            this.targetNode = target;
            this.weight = weight;
        }

    }

    public static class Graph {
        List<List<Edge>> adjust;

        public Graph(int n) {
            adjust = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                adjust.add(new ArrayList<>());
            }
        }

        public void addEdge(int source, int target, int weight) {
            adjust.get(source).add(new Edge(target, weight));
            adjust.get(target).add(new Edge(source, weight));
        }

        public List<Edge> getEdges(int node) {
            return adjust.get(node);
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        weightedGraph = new Graph(n);
        isVisited = new boolean[n + 1];

        for (int i = 0; i < n - 1; i++) {
            String[] input = br.readLine().split(" ");
            int source = Integer.parseInt(input[0]);
            int target = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);

            weightedGraph.addEdge(source, target, weight);
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, 0);
        }
        System.out.println(maxWeight);
    }

    public static void dfs(int node, int totalWeight) {
        isVisited[node] = true;
        List<Edge> edges = weightedGraph.getEdges(node);
        for (Edge edge : edges) {
            if (!isVisited[edge.targetNode]) {
                dfs(edge.targetNode, totalWeight + edge.weight);
            }
        }
        maxWeight = Math.max(maxWeight, totalWeight);
        isVisited[node] = false;
    }
}
