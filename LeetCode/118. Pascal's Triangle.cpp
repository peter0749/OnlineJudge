class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int nr = 0; nr < numRows; ++nr) {
            vector<int> temp;
            temp.push_back(1);
            if (nr>=2)
                for (int i=0; i<nr-1; ++i)
                    temp.push_back(ret[nr-1][i]+ret[nr-1][i+1]);
            if (nr>=1)
                temp.push_back(1);
            ret.push_back(temp);
        }
        return ret;
    }
};
