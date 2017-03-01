//Build, Query: O(nm), O(n)
public class NumMatrix {
    private int [][] prefix;
    private int partial_sum(int a, int b, int h) {
        return prefix[h][b+1] - prefix[h][a];
    }
    public NumMatrix(int[][] matrix) {
        if(matrix.length==0) return;
        prefix = new int[matrix.length][matrix[0].length+1];
        for(int i=0; i!=matrix.length; ++i) {
            for(int j=1; j!=prefix[0].length; ++j) {
                prefix[i][j] = prefix[i][j-1]+matrix[i][j-1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(prefix==null) return 0;
        int sums=0;
        for(int i=row1; i<=row2; ++i) {
            sums += partial_sum(col1, col2, i);
        }
        return sums;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

public class NumMatrix {
    private int [][] prefix;
    public NumMatrix(int[][] matrix) {
        prefix = null;
        if(matrix.length==0) return;
        prefix = new int[matrix.length+1][matrix[0].length+1];
        for(int i=1; i!=prefix.length; ++i) {
            for(int j=1; j!=prefix[0].length; ++j) {
                prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    // Build: O(nm); Query: O(1)
    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(prefix==null) return 0;
        int sums = ( prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1] );
        return sums;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
