import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 방울마술_20934 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int n=1;

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String S = st.nextToken();
            int K = Integer.parseInt(st.nextToken());

            int oPos = S.indexOf("o");
            if(K==0){
                System.out.println("#"+n+" "+oPos);
            }
            else {
                if (oPos == 0 || oPos==2) {
                    if (K % 2 == 0) {
                        System.out.println("#"+n+" "+0);
                    } else {
                        System.out.println("#"+n+" "+1);
                    }
                }
                if (oPos == 1) {
                    if (K % 2 == 0) {
                        System.out.println("#"+n+" "+1);
                    } else {
                        System.out.println("#"+n+" "+0);
                    }
                }
            }

            n++;
        }
    }
}
