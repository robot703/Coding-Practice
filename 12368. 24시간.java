import java.util.*;
import java.math.*;;

class Solution {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int firsttime = 0;
		int sumtime = 0;
		int totaltime = 0;
		int T = sc.nextInt();
		
		for(int i=1; i<=T; i++) {
			sumtime = 0;
			totaltime = 0;
			firsttime = sc.nextInt();
			sumtime = sc.nextInt();
			totaltime = firsttime + sumtime;
			if(totaltime>=24) {
				System.out.println("#" + i + " " + totaltime%24);
			}
			else {
				System.out.println("#" + i + " " + totaltime);
			}
		}
	}
}
		

	
