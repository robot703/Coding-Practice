import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 묶음판매_22759{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for(int T=0; T<t; T++){
            String [] input = br.readLine().split(" ");
            int L = Integer.parseInt(input[0]);
            int R = Integer.parseInt(input[1]);

            if(L < (R+1)/2.0){
                System.out.println("no");
            }
            else{
                System.out.println("yes");
            }
        }

    }
}