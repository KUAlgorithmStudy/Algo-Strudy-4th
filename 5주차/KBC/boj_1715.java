import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

//BOJ 1715 [카드 정렬하기]
/* 큰 수의 카드 팩이 최대한 덜 사용 되도록 하기
*  작은 카드 팩부터 뽑아 사용
*  정렬을 위해 우선 순위 큐 사용 */
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Integer> cards = new PriorityQueue<>();
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            cards.add(Integer.parseInt(br.readLine()));
        }

        int count = 0;
        for (int i = 1; i < n; i++) {
            int newCard = cards.poll() + cards.poll();
            cards.add(newCard);
            count += newCard;
        }

        System.out.println(count);
    }
}