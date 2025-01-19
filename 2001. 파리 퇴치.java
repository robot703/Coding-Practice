import java.util.*;


public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int [][] arr = new int[N][N];
			int [][] prefix = new int[N+1][N+1];
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					arr[i][j]=sc.nextInt();
					prefix[i+1][j+1]= arr[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
				}
			}
			int maxFiles=0;
			
			for(int i=M; i<=N; i++) {
				for(int j=M; j<=N; j++) {
					int files = prefix[i][j]-prefix[i-M][j]
							-prefix[i][j-M]+prefix[i-M][j-M];
					maxFiles = Math.max(maxFiles, files);
				}
			}
			
			System.out.printf("#%d %d\n", t, maxFiles);
		}
		sc.close();
	}
}
