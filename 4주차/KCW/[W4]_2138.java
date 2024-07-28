package W4;

import java.util.*;
import java.io.*;

public class W4_2138 {
	static int N, cur[], ans[], arr[];

	public static int solution(int a[]) {
		int cnt = 0;
		for (int i = 0; i < N-1; i++) {
			// 바꿀까말까
			if(a[i] != ans[i]) {
				a[i] = 1 - a[i];
				a[i + 1] = 1 - a[i + 1];
				if(i != N-2)
					a[i + 2] = 1 - a[i + 2];
				cnt++;
			}
		}
		
		return a[N-1]!=ans[N-1] ? -1 : cnt;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		cur = new int[N];
		ans = new int[N];
		String str = br.readLine();
		for (int i = 0; i < N; i++) {
			cur[i] = str.charAt(i) - '0';
		}
		str = br.readLine();
		for (int i = 0; i < N; i++) {
			ans[i] = str.charAt(i) - '0';
		}

		arr = Arrays.copyOf(cur, N);
		arr[0] = 1 - arr[0];
		arr[1] = 1 - arr[1];
		int ans1 = solution(cur);
		int ans2 = solution(arr);
		if(ans2 != -1) ans2++;
		
		if(ans1 == -1)
			System.out.println(ans2);
		else if(ans2 == -1) 
			System.out.println(ans1);
		else
			System.out.println(Math.min(ans1, ans2));
	}

}
