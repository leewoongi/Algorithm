
class Solution{
	    public String solution(String number, int k) {
	        StringBuilder answer = new StringBuilder();
	        int idx = 0;
	        char max = '0';
	        for(int i = 0; i<number.length()-k; i++){
	            max = '0';
	            for(int j = idx; j<=k+i; j++){
	                if(max < number.charAt(j)){
	                    max = number.charAt(j);
	                    idx = j+1;
	                }
	            }
	            answer.append(max);
	        }
	        return answer.toString();
	    }
	}

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution sl = new Solution();
		
		System.out.println(sl.solution("4177252841", 4));
	}
}
