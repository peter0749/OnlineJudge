// Top-down
class Solution {
public:
    int memory[46] = {0};
    int climbStairs(int n) {
        if (n<=1)
            return 1;
        if (memory[n]!=0)
            return memory[n];
        return memory[n] = climbStairs(n-2) + climbStairs(n-1);
    }
};

// Bottom-up
class Solution {
public:
    int dp[46] = {0};
    int climbStairs(int n) {
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<=n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

// Iterative
class Solution {
public:
    int climbStairs(int n) {
        int x1=1, x2=1;
        if (n<=1) return 1;
        for (int i=2; i<=n; ++i) {
            int x3 = x2 + x1;
            x1 = x2;
            x2 = x3;
        }
        return x2;
    }
};
