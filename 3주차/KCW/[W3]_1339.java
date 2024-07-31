package W3;

import java.io.*;
import java.util.*;

public class W3_1339 {
	static int N;
	static String a, b;
	static boolean used[] = new boolean[10];
	static int alphabet[] = new int[10];
	static PriorityQueue<priorityAlphabet> pQ = new PriorityQueue<>(Collections.reverseOrder());
	
	//make priorityAlphabet class for priority queue
	static class priorityAlphabet implements Comparable<priorityAlphabet>{
		int priority;
		char alphabet;
		public priorityAlphabet(int priority, char alphabet) {
			this.priority = priority;
			this.alphabet = alphabet;
		}
		public int compareTo(priorityAlphabet pA) {
			if(this.priority < pA.priority) return -1;
			else if(this.priority > pA.priority) return 1;
			return 0;
		}
	}
	public static void putpQ(String str) {
		int len = str.length();
		int cnt = 0;
		for(int i = 0; i<len; i++) {
			char ch = str.charAt(i);
			priorityAlphabet pA = new priorityAlphabet(len-i, ch);
			cnt++;
			pQ.add(pA);
		}
	}
	public static String exchange(String str) {
		String result = "";
		for(int i = 0; i<str.length();i++) {
			int index = str.charAt(i) - 'A';
			result += alphabet[index];
		}
		return result;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine().trim());
		a = br.readLine().trim();
		b = br.readLine().trim();

		//put to priority queue
		putpQ(a);
		putpQ(b);
		
		//set number to each alphabet
		int num = 9;
		for(; !pQ.isEmpty();) {
			priorityAlphabet pA = pQ.poll();
			char ch = pA.alphabet;
			alphabet[ch-'A'] = num--;
		}
		
		//exchange
		String numA = exchange(a);
		String numB = exchange(b);
		
		//sum
		int sum = Integer.parseInt(numA) + Integer.parseInt(numB);
		System.out.println(numA+" "+numB);

	}

}
