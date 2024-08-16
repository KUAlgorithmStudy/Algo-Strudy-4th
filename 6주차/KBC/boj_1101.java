import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//BOJ 1011 [Fly me to the Alpha Centauri]
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int[] pos = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int distance = pos[1] - pos[0];
            int count = calculateCount(distance);
            System.out.println(count);
        }
    }
    public static int calculateCount(int distance) {
        if(distance == 1) {
            return 1;
        }

        boolean isEven = false;
        int count = 2;
        int k = 2;

        distance -= 2;
        while(distance > 0) {
            distance -= k;
            count++;
            if(isEven) {
                k++;
            }
            isEven = !isEven;
        }
        return count;
    }
}
/*
1 : 1 : 1

2 : 1 1 : 2

3 : 1 1 1 : 3
4 : 1 2 1 : 3
5 : 1 2 1 1 : 4
6 : 1 2 2 1 : 4

7 : 1 2 2 1 1 : 5
8 : 1 2 2 2 1 : 5
9 : 1 2 3 2 1 : 5
10 : 1 2 3 2 1 1 : 6
11 : 1 2 3 2 2 1 : 6
12 : 1 2 3 3 2 1 : 6

13 : 1 2 3 3 2 1 1 : 7
14 : 1 2 3 3 2 2 1 : 7
15 : 1 2 3 3 3 2 1 : 7
16 : 1 2 3 4 3 2 1 : 7
17 : 1 2 3 4 3 2 1 1 : 8
18 : 1 2 3 4 3 2 2 1 : 8
19 : 1 2 3 4 3 3 2 1 : 8
20 : 1 2 3 4 4 3 2 1 : 8

21 : 1 2 3 4 4 3 2 1 1 : 9
 */