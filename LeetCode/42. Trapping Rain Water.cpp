class Solution {
public:
    // Solution using DP
    // TODO: Solution using stack
    int trap(vector<int>& height) {
        if (height.size()==0) return 0;
        int N = height.size();
        
        int *DP_left = new int[N];
        int *DP_right = new int[N];
        fill(DP_left, DP_left+N, 0);
        fill(DP_right, DP_right+N, 0);
        
        DP_right[0] = height[0];
        DP_left[N-1] = height[N-1];
        for (int i=1; i<N; ++i) {
            DP_right[i] = max(DP_right[i-1], height[i]);
            DP_left[N-1-i] = max(DP_left[N-i], height[N-1-i]);
        }
        
        int sum = 0;
        for (int i=0; i<N; ++i) {
            sum += min(DP_left[i], DP_right[i]) - height[i];
        }
        
        delete[] DP_left; DP_left=NULL;
        delete[] DP_right; DP_right=NULL;
        return sum;
    }
};
