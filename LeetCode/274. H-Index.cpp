class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 6 5 3 1 0
        if (citations.size() == 0) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i=0; i<citations.size(); ++i) {
            if (citations[i] >= i+1)
                if (i+1 == citations.size() || citations[i+1] <= i+1)
                    h = i+1;
        }
        return h;
    }
};
