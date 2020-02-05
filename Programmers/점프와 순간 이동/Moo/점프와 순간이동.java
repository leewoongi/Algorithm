package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	
	public int solution(int n) {
		int ans = 0;
		
		int first = 0;
		int last = n; // 5000

		if (n % 2 == 0) {
			last = n;
		} else {
			last = n - 1;
			ans++;
		}

		while (first < last) {
			int middle = (first + last) / 2; // 2500
			last = middle; // last = 2500
			if (last % 2 == 0) {
				last = last / 2; // last = 625
			}
			if (last % 2 == 1) {
				last = last - 1;
				ans++;
			}
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		System.out.println(new Solution().solution(N));
	}
}
