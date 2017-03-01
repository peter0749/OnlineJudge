import java.util.Scanner;

class ThNOne {
    private int counter;
    private int n31(long n) {
        this.counter++;
        if(n==1) return counter;
        if(n%2==0) { //n is even
            return n31(n>>1);
        } else { // odd
            return n31(3*n+1);
        }
    }
    public static long[] reass(long a1, long a2) {
        return new long[]{a2,a1};
    }
    public long solv(long l, long r) {
        if(l>r) {
            long[] sw = reass(l,r);
            l=sw[0]; r=sw[1];
        }
        long maxv=-1;
        for( long i=l; i<=r; ++i) {
            this.counter=0;
            maxv = Math.max( n31(i), maxv);
        }
        this.counter=0;
        return maxv;
    }
    public ThNOne() {
        this.counter=0;
    }
};

class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        ThNOne NN = new ThNOne();
        long l, r;
        while ( scan.hasNext() ) {
            l = scan.nextLong(); r=scan.nextLong();
            System.out.println( l+" "+r+" "+ NN.solv(l, r) );
        }
    }
};
