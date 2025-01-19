import java.util.*;
import java.math.*;;

class Solution {
	
	public static void main(String[] args) {
		int sum=0;
		Scanner sc = new Scanner(System.in);
		
		int T=sc.nextInt();
		int result=0;
		for(int j=1; j<=T; j++) {
			for(int i=0; i<10; i++) {
				int a = sc.nextInt();
				sum+=a;
                result = (int)Math.round(sum/10.0);
			}
			System.out.println("#"+j+" "+result);
			sum=0;
		}		
	}
}
		

	
