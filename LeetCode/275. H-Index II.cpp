class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        //for (int i=0; i<N; ++i) {
        //    cout << i << " " << (citations[i]>=N-i) << endl;
        //}
        // Observe input:
        // 0 1 3 5 7 9
        // 0 0 1 1 1 1
        //     * <-- find this
        // 0 0 4 3 2 1 = h, find maximal h
        if (N==1)
            return min(citations[0], 1);
        int l=0, r=N; // [left, right)
        // 0 0 1 1 1 1
        // l           r (init)
        //   l r         (final case 1)
        //    l=r        (final case 2)
        while (r-l>1) {
            int m = l + (r-l) / 2;
            if (citations[m]>=N-m)
                r = m;
            else
                l = m + 1;
        }
        // case 1
        if (l<N && citations[l]>=N-l)
            return N-l;
        ++l;
        // case 2
        if (l<N && citations[l]>=N-l)
            return N-l;
        return 0;
    }
};
