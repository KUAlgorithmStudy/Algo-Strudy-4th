package W3;
import java.io.*;
import java.util.*;

public class W3_14889 {
	static int N, S[][];
	static boolean start[];
	static int minAbility = Integer.MAX_VALUE;
	static void abilitySub() {
		int startScore = 0, linkScore = 0;
		for(int i = 0; i<N; i++) {			
			for(int j = i+1; j<N; j++) {
				if(start[i] && start[j]) {
					startScore += S[i][j] + S[j][i];
				}
				else if(!start[i] && !start[j]){
					linkScore += S[i][j] + S[j][i];
				}
			}
		}		
		minAbility = Math.min(Math.abs(startScore-linkScore),minAbility);
		if(minAbility == 0) {
			System.out.println(minAbility);
			System.exit(0);
		}
	}
	static void dfs(int depth, int num) {
		if(depth == N/2) {
			abilitySub();		
			return;
		}
		for(int i = num; i<N; i++) {// 중복 방지를 위해 team배열은 오름차순임
			start[i] = true;
			dfs(depth+1, i+1);
			start[i] = false;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine().trim());
		start = new boolean[N];
		S = new int[N][N];
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int j = 0; j < N; j++) {
				S[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(0, 0);
		
		System.out.println(minAbility);
		
	}

}
