package W4;

import java.io.*;
import java.util.*;

public class W4_1080 {
	static int N, M, matA[][], matB[][], cnt;

	static void reverse(int n, int m) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matA[i + n][j + m] = 1 - matA[i + n][j + m];
			}
		}
	}

	static boolean isEqualArr(int a[][], int b[][]) {
		for (int i = 0; i < a.length; i++) {
			if (!Arrays.equals(a[i], b[i])) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		matA = new int[N][M];
		matB = new int[N][M];
		for (int i = 0; i < N; i++) {
			String str = new String(br.readLine());
			for (int j = 0; j < M; j++) {
				matA[i][j] = str.charAt(j) - '0';
			}
		}
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				matB[i][j] = str.charAt(j) - '0';
			}
		}
		if (N < 3 || M < 3) {
			// N이나 M이 3보다 작으면 변환이 불가능하므로 바로 비교 결과 출력
			if (isEqualArr(matA, matB)) {
				System.out.println(0);
			} else {
				System.out.println(-1);
			}
			return;
		}

		for(int i = 0; i<N-2; i++) {
			for(int j = 0; j<M-2 ;j++) {
				if(matA[i][j] != matB[i][j]) {
					reverse(i, j);
					cnt++;
				}
			}
		}
		if(isEqualArr(matA, matB))
			System.out.println(cnt);
		else
			System.out.println(-1);
	}
}
