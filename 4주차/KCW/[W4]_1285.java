package W4;

import java.io.*;

public class W4_1285 {
	static int N, min = Integer.MAX_VALUE;
	static char coins[][];

	static char reverse(char value) {
		if (value == 'T')
			return 'H';
		else
			return 'T';
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		coins = new char[N][N];
		for (int i = 0; i < N; i++) {
			coins[i] = br.readLine().toCharArray();
		}
		
		for(int bitCase = 0; bitCase < (1<<N); bitCase++) { // 행을 뒤집는 경우의 수
			int sum = 0;
			for(int j = 0; j<N; j++) {// 각 열에서 뒷면 개수 세기 ( 뒤집은게 안뒤집은거보다 뒷면 개수가 적으면 뒤집기)
				int count = 0;
				for(int i = 0; i<N; i++) {
					char tmp = coins[i][j];
					if((bitCase & (1 << i )) != 0) // 해당하는 행이면 뒤집기
						tmp = reverse(tmp);
					if(tmp == 'T') count++;
				}
				sum += Math.min(count, N-count);
			}
			min = Math.min(min, sum);
		}
		
		System.out.println(min);
		br.close();
	}
}
