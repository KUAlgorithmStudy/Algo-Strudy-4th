import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//BOJ 11728 [배열 합치기]
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int[] lengths = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] array1 = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] array2 = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int i = 0;
        int k = 0;
        while (i < lengths[0] && k < lengths[1]) {
            if (array1[i] < array2[k]) {
                sb.append(array1[i]).append(" ");
                i++;
            } else {
                sb.append(array2[k]).append(" ");
                k++;
            }
        }

        while (i < lengths[0]) {
            sb.append(array1[i]).append(" ");
            i++;
        }
        while (k < lengths[1]) {
            sb.append(array2[k]).append(" ");
            k++;
        }
        System.out.println(sb);
    }
}
