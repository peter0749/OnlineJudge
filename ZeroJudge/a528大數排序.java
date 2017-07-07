import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        BigInteger[] arr;
        while (scanner.hasNext()) {
            int term = scanner.nextInt();
            arr = new BigInteger[term];
            scanner.nextLine();
            for (int i=0; i<term; ++i) {
                String str = scanner.nextLine();
                arr[i] = new BigInteger(str);
            }
            Arrays.sort(arr);
            for (BigInteger v: arr)
                System.out.println(v);
        }
    }
}


