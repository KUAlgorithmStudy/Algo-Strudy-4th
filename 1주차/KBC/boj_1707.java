import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

//BOJ 1707 [이분그래프]
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input;

        for (int i = 0; i < n; i++) {
            Set<Integer> leftVertice = new HashSet<>();
            Set<Integer> rightVertice = new HashSet<>();

            String message = "YES";
            input = br.readLine().split(" ");

            int maxVertex = Integer.parseInt(input[0]);
            int maxEdge = Integer.parseInt(input[1]);
            boolean[] isVisit = new boolean[maxEdge];
            int[][] edges = new int[maxEdge][2];

            for (int j = 0; j < maxEdge; j++) {
                input = br.readLine().split(" ");
                int start = Integer.parseInt(input[0]);
                int end = Integer.parseInt(input[1]);
                edges[j][0] = start;
                edges[j][1] = end;
            }

            for(int j=0; j<maxEdge; j++) {
                if(!isVisit[j]) {
                    //최초 등장하는 양 정점이라면 등록
                    if(!leftVertice.contains(edges[j][0]) && !rightVertice.contains(edges[j][0]) &&
                    !leftVertice.contains(edges[j][1]) && !rightVertice.contains(edges[j][1])) {
                        leftVertice.add(edges[j][0]);
                        rightVertice.add(edges[j][1]);
                    }
                    //이미 등록된 정점에 의해 순서가 정해진다면 등록
                    //그게 아니라면 보류
                    for(int k=j+1; k<maxEdge; k++) {
                        isVisit[k] = true;
                        if(leftVertice.contains(edges[k][0])) {
                            rightVertice.add(edges[k][1]);
                        }
                        else if(rightVertice.contains(edges[k][0])) {
                            leftVertice.add(edges[k][1]);
                        }
                        else if(leftVertice.contains(edges[k][1])) {
                            rightVertice.add(edges[k][0]);
                        }
                        else if(rightVertice.contains(edges[k][1])) {
                            leftVertice.add(edges[k][0]);
                        }
                        else {
                            isVisit[k] = false;
                        }
                    }
                }
            }
            for (int nVertex = 1; nVertex <= maxVertex; nVertex++) {
                if (leftVertice.contains(nVertex) && rightVertice.contains(nVertex)) {
                    message = "NO";
                    break;
                }
            }
            System.out.println(message);
        }
    }
}