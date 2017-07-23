import java.util.*;
import java.math.BigInteger;

class pE {
    public static void main(String args[]) {
        final int fib_Size=5010;
        BigInteger[] fib = new BigInteger[fib_Size];
        fib[0] = new BigInteger("0");
        fib[1] = new BigInteger("1");
        for (int i=2; i<fib_Size; ++i) {
            fib[i] = fib[i-1].add(fib[i-2]); // no problem
        }
        Scanner scanner = new Scanner(System.in);
        while( scanner.hasNext() ) {
            Integer query = scanner.nextInt();
            scanner.nextLine(); // pick-up newline
            System.out.println("The Fibonacci number for " + query + " is " + fib[query]);
        }
    }
}
