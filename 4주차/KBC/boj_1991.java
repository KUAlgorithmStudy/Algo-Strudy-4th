import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//BOJ 1991 [트리 순회]
public class Main {
    private static int[] pos;
    private static char[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        arr = new char[(int) Math.pow(2, n + 1) - 1]; //트리 노드의 최대개수
        pos = new int[n];

        pos[0] = 0; //A의 위치값은 항상 루트
        arr[0] = 'A';

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            char parent = input[0].charAt(0);
            char LChild = input[1].charAt(0);
            char RChild = input[2].charAt(0);
            setLSubNode(parent, LChild);
            setRSubNode(parent, RChild);
        }

        preOrder(0);
        System.out.println();
        inOrder(0);
        System.out.println();
        postOrder(0);
    }

    public static void setLSubNode(char parent, char LChild) {
        if (LChild == '.') {
            return;
        }
        pos[LChild - 'A'] = pos[parent - 'A'] * 2 + 1; //왼쪽자식
        arr[pos[LChild-'A']] = LChild;
    }

    public static void setRSubNode(char parent, char RChild) {
        if (RChild == '.') {
            return;
        }
        pos[RChild - 'A'] = pos[parent - 'A'] * 2 + 2; //오른쪽자식
        arr[pos[RChild-'A']] = RChild;
    }
    public static void preOrder(int pos) {
        if(pos >= arr.length || arr[pos] == '\0') {
            return;
        }
        System.out.print(arr[pos]);
        preOrder(pos*2 +1);
        preOrder(pos*2 +2);
    }
    public static void inOrder(int pos) {
        if(pos >= arr.length || arr[pos] == '\0') {
            return;
        }
        inOrder(pos*2 +1);
        System.out.print(arr[pos]);
        inOrder(pos*2 +2);
    }
    public static void postOrder(int pos) {
        if(pos >= arr.length || arr[pos] == '\0') {
            return;
        }
        postOrder(pos*2 +1);
        postOrder(pos*2 +2);
        System.out.print(arr[pos]);
    }
}
