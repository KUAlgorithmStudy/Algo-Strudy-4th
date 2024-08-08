import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//BOJ 2212 [센서]

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());
        int[] censors = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        Arrays.sort(censors);
        //가까운 센서들 끼리 그룹화(다음 센서와의 거리가 크다면 그 이전까지 그룹. K개의 그룹 생성)
        //그룹화 당 하나의 집중국이므로 거리 더하기

        //다음 센서까지의 거리
        int[] distances = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            distances[i] = censors[i + 1] - censors[i];
        }
        Arrays.sort(distances);

        int result = 0;
        //distance N-1개 중 K-1개 제외
        for (int i = 0; i < N - K; i++) {
            result += distances[i];
        }

        System.out.println(result);
    }
}
