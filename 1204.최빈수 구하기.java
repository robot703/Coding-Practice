import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = Integer.parseInt(scanner.next());

        for(int i=0; i<T; i++){
            int a = Integer.parseInt(scanner.next());
            int [] List = new int[101];
            Arrays.fill(List,0);

            int max = List[0];
            int maxIndex = 0;

            for(int j=0; j<1000; j++){
                int b = Integer.parseInt(scanner.next());
                List[b]++;
            }
            for(int j=1; j<=100; j++){
                if (List[j] > max || (List[j] == max && j > maxIndex)) {
                    max = List[j];
                    maxIndex = j;
                }
            }
            System.out.println("#" + (i+1) + " " + maxIndex);
        }
    }
}
