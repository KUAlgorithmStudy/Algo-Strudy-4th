package W3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class W3_2529 {
	static int k;
	static long max = Long.MIN_VALUE;
	static long min = Long.MAX_VALUE;
	static String dmax, dmin;
	static char input[];
	static boolean used[] = new boolean[10];
	
	public static void dfs(int depth, String result) {
		if (depth == k + 1) {
			long tmp = Long.parseLong(result);
			if (tmp > max) {
				max = tmp;
				dmax = result;
			}
			if (tmp < min) {
				min = tmp;
				dmin = result;
			}
			return;
		}
		for (int i = 0; i < 10; i++) {
			if (used[i]) continue;
			
			if (result.equals("")) {
				used[i] = true;
				dfs(depth + 1, result + i);
				used[i] = false;
			} else if (input[depth - 1] == '<') {
				int n = result.charAt(depth - 1) - '0';
				if (n < i) {
					used[i] = true;
					dfs(depth + 1, result + i);
					used[i] = false;
				}
			} else if (input[depth - 1] == '>') {
				int n = result.charAt(depth - 1) - '0';
				if (n > i) {
					used[i] = true;
					dfs(depth + 1, result + i);
					used[i] = false;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		k = Integer.parseInt(br.readLine().trim());
		input = new char[k];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < k; i++) {
			String str = st.nextToken();
			input[i] = str.charAt(0);
		}
		dfs(0, "");
		System.out.println(dmax);
		System.out.println(dmin);
	}
}
