import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//BOJ 9934 [완전 이진 트리]
public class Main {
    private static StringBuilder[] result;
    private static int[] input;
    private static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        result = new StringBuilder[n + 1];
        for (int i = 0; i <= n; i++) {
            result[i] = new StringBuilder();
        }

        //입력값 input배열에 등록
        input = new int[(int) Math.pow(2, n)];
        String[] str = br.readLine().split(" ");
        for (int i = 1; i <= str.length; i++) {
            input[i] = Integer.parseInt(str[i - 1]);
        }

        //1 3 5 7... 번째 = N층
        //2 6 10 14 ... 번째 = N-1층
        //2^n, 2^n + 2^(n+1), 2^n + 2^(n+1) + 2^(n+1), ... 번째 = N-n층
        for (int level = 0; level < n; level++) {
            int i = 0;
            int init = (int) Math.pow(2, level);
            int distance = (int) Math.pow(2, level + 1);

            int index;
            while (str.length + 1 > (index = init + distance * i)) {
                result[n - level].append(input[index]).append(" ");
                i++;
            }
        }

        for (int level = 1; level <= n; level++) {
            System.out.println(result[level]);
        }
    }
}
