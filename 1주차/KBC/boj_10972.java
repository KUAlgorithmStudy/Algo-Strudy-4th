import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//BOJ 10972 [다음 순열]

//내림차순 찾기
//내림차순 이전 값을 내림차순의 최소값이랑 swap
//내림차순을 오름차순으로 정렬
public class Main {
    static int[] arr;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        int pivotIndex = getPivotIndex();
        if (pivotIndex < 0) {
            System.out.println(-1);
            return;
        }
        setNextPermutation(pivotIndex);

        for (int i = 0; i < N; i++) {
            sb.append(arr[i]).append(" ");
        }
        System.out.println(sb);
    }

    public static int getPivotIndex() {
        int i = N - 2;
        while (i >= 0 && arr[i] > arr[i + 1]) {
            i--;
        }
        return i;
    }

    public static void setNextPermutation(int pivotIndex) {
        int target = N - 1;
        while (arr[pivotIndex] > arr[target]) {
            target--;
        }
        swap(pivotIndex, target);

        int p = pivotIndex + 1;
        int q = N - 1;
        while (p < q) {
            swap(p, q);
            p = p + 1;
            q = q - 1;
        }
    }

    public static void swap(int p1, int p2) {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
    }
}