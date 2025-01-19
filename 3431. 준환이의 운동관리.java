import java.util.*;
import java.math.*;;

class Solution {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int a,b,c;
		
		for(int i=1; i<=T; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			if(c<a)
				System.out.printf("#%d %d%n", i, a-c);
			else if(c>=a && c<=b)
				System.out.printf("#%d 0\n",i);
			else
				System.out.printf("#%d -1\n",i);
		}
	}
}
		

	
