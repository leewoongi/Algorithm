package programmers;

class Solution {
	
	public int solution(int sticker[]) {    
		int answer = 0;
		
		int dp1[] = new int[100001];
		int dp2[] = new int [100001];
		
		int len = sticker.length;
		
		if(len == 1) {
			return sticker[0];
		}
		
		//1번 스티커 뜯을겨우
		dp1[0] = sticker[0];
		dp1[1] = dp1[0];
		
		for(int i = 2; i<len - 1; i++) {
			dp1[i] = Math.max(dp1[i-1], sticker[i] + dp1[i-2]);
		}
		
		//2번 스티커 뜯을경우
		dp2[0] = 0;
		dp2[1] = sticker[1];
		
		for(int i = 2; i<len; i++) {
			dp2[i] = Math.max(dp2[i-1], dp2[i-2] + sticker[i]); 
		}
		
		return Math.max(dp1[len-2], dp2[len-1]);	
    }
	
	public static void main(String[] args) {
		Solution s = new Solution();
		int sticker[] = {14, 6, 5, 11, 3, 9, 2, 10};
		System.out.println(s.solution(sticker));
		
	}
}

