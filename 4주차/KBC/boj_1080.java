import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//BOJ 1080 [행렬]
public class Main {
    public static int[][] A;
    public static int[][] B;
    public static int maxHeight;
    public static int maxWidth;
    public static int count;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        initialize(br);
        searchMatrix();
        validMatrix();

        System.out.println(count);
    }

    public static void initialize(BufferedReader br) throws IOException {
        String[] size = br.readLine().split(" ");
        maxHeight = Integer.parseInt(size[0]);
        maxWidth = Integer.parseInt(size[1]);

        //최대 크기 matrix로 설정
        A = new int[51][51];
        B = new int[51][51];

        for (int i = 0; i < maxHeight; i++) {
            A[i] = Arrays.stream(br.readLine().split(""))
                    .mapToInt(Integer::parseInt)
                    .toArray();
        }
        for (int i = 0; i < maxHeight; i++) {
            B[i] = Arrays.stream(br.readLine().split(""))
                    .mapToInt(Integer::parseInt)
                    .toArray();
        }
        //flip 횟수
        count = 0;
    }

    public static void searchMatrix() {
        //모든 flip가능한 위치 탐색
        for (int h = 0; h < maxHeight - 2; h++) {
            for (int w = 0; w < maxWidth - 2; w++) {
                //원소가 다르면 flip
                if(A[h][w] != B[h][w]) {
                    flip(h, w);
                    count++;
                }
            }
        }
    }

    public static void flip(int height, int width) {
        for (int h = height; h < height + 3; h++) {
            for (int w = width; w < width + 3; w++) {
                A[h][w] = (A[h][w] == 1 ? 0 : 1);
            }
        }
    }

    public static void validMatrix() {
        for (int h = 0; h < maxHeight; h++) {
            for (int w = 0; w < maxWidth; w++) {
                if (A[h][w] != B[h][w]) {
                    count = -1;
                    return;
                }
            }
        }
    }
}