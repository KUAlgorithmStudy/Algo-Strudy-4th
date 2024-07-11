import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


//BOJ 11724 [연결 요소의 개수]
public class Main {
    private static boolean[] isConnect;
    private static boolean[] isVisit;
    private static int totalNumberVertice;
    private static int totalNumberEdges;
    private static boolean[][] matrix;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        totalNumberVertice = Integer.parseInt(input[0]);
        totalNumberEdges = Integer.parseInt(input[1]);
        matrix = new boolean[totalNumberVertice + 1][totalNumberVertice + 1];
        isConnect = new boolean[totalNumberVertice + 1];
        isVisit = new boolean[totalNumberVertice + 1];

        for (int nEdge = 1; nEdge <= totalNumberEdges; nEdge++) {
            String[] edge = br.readLine().split(" ");
            int v1 = Integer.parseInt(edge[0]);
            int v2 = Integer.parseInt(edge[1]);

            matrix[v1][v2] = true;
            matrix[v2][v1] = true;
        }

        int nVertex = 1;
        int result = 0;
        while (true) {
            isConnect[nVertex] = false;
            isVisit[nVertex] = true;
            for (int k = 1; k <= totalNumberVertice; k++) {
                if (matrix[nVertex][k]) {
                    matrix[nVertex][k] = false;
                    matrix[k][nVertex] = false;
                    isConnect[k] = true;
                }
            }
            if ((nVertex = getNextConnect()) > totalNumberVertice) {
                result++;
                if ((nVertex = getNextVertex()) > totalNumberVertice) {
                    break;
                }
            }
        }
        System.out.println(result);
    }

    public static int getNextVertex() {
        int nVertex;
        for (nVertex = 1; nVertex <= totalNumberVertice; nVertex++) {
            if (!isVisit[nVertex]) {
                break;
            }
        }
        return nVertex;
    }

    public static int getNextConnect() {
        int nVertex;
        for (nVertex = 1; nVertex <= totalNumberVertice; nVertex++) {
            if (isConnect[nVertex]) {
                break;
            }
        }
        return nVertex;
    }
}
