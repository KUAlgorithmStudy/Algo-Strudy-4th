package W3;

import java.io.*;
import java.util.*;

public class W2_16929{
	static int N,M, curX, curY;
	static char[][] dots;	//dots 보드 배열
	static int[] dx = {0, 0, -1, 1};	//상, 하, 좌, 우 x값 변경값
	static int[] dy = {-1, 1, 0, 0};	//상, 하, 좌, 우 y값 변경값
	static boolean[][] visited;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        	//입력값 처리하는 BufferedReader
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        	//결과값 출력하는 BufferedWriter
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		dots = new char[N][M];
        	//dots 보드 저장
		for(int i=0;i<N;i++) {
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				dots[i][j] = str.charAt(j);
			}
		}
        	//각 점을 시작으로 사이클이 존재하는지 DFS로 탐색
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				visited = new boolean[N][M];
				visited[i][j] = true;
				curX = j;
				curY = i;
				dfs(j,i, dots[i][j],1);
			}
		}
		bw.write("No\n");	//사이클 존재하지 않을 때 "No" BufferedWriter 저장
		bw.flush();		//결과 출력
		bw.close();
		br.close();
	}
    	//사이클이 존재하는지 확인하는 DFS 함수
	static void dfs(int x, int y, char dot, int count) {
		for(int i=0;i<4;i++) {
			int tempX = x + dx[i];	//x값 변경
			int tempY = y + dy[i];	//y값 변경
			if(tempX>=0 && tempX<M && tempY>=0 && tempY<N && dots[tempY][tempX] == dot) {
				if(!visited[tempY][tempX]) {
					visited[tempY][tempX] = true;
					dfs(tempX,tempY,dot,count+1);
				}else {
                			//점을 4개를 지나며 사이클일 때
					if(count>=4 && tempX==curX && tempY==curY) {
						System.out.println("Yes\n");	//"Yes" 결과 출력
						System.exit(0);			//코드 종료
					}
				}
			}
		}
		return;
	}
}