import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//BOJ 2138 [전구와 스위치]
public class Main {
    private static int N; // 2~ 100,000
    private static int[] A;
    private static int[] B;
    private static int[] result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        initialize(br);
        int count1 = search(A, 0);
        int count2 = search(B, 1);

        printResult(count1, count2);
    }

    public static void initialize(BufferedReader br) throws IOException {
        N = Integer.parseInt(br.readLine());
        A = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
        B = A.clone();
        B[0] = B[0] == 1 ? 0 : 1;
        B[1] = B[1] == 1 ? 0 : 1;
        result = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
    }

    public static int search(int[] array, int count) {
        for (int i = count; i < N; i++) {
            if (!isEquals(i - 1, array)) {
                flip(i - 1, array);
                flip(i, array);
                flip(i + 1, array);
                count++;
            }
        }

        if (!Arrays.equals(array, result)) {
            count = -1;
        }
        return count;
    }

    public static boolean isEquals(int i, int[] array) {
        if (isValidRange(i)) {
            return true;
        }
        return array[i] == result[i];

    }

    public static void flip(int i, int[] array) {
        if (isValidRange(i)) {
            return;
        }
        array[i] = array[i] == 1 ? 0 : 1;
    }

    public static boolean isValidRange(int i) {
        return i < 0 || i >= N;
    }

    public static void printResult(int count1, int count2) {
        if (count1 < 0 && count2 < 0) {
            System.out.println(-1);
        } else if (count1 < 0) {
            System.out.println(count2);
        } else if (count2 < 0) {
            System.out.println(count1);
        } else {
            System.out.println(Math.min(count1, count2));
        }
    }
}