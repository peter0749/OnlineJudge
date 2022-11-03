class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> bIsPrime(n,true);
        
        int cnt = 0;
        for (long long i=2; i<n; ++i) {
            if (bIsPrime[i]) {
                for (long long j=i*i; j<n; j+=i)
                    bIsPrime[j] = false;
                ++cnt;
            }
        }
        return cnt;
    }
};
