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
