#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        size_t N;
        vector<int> data;
    public:
        inline void read_data(){
            cin>>this->N;
            for(size_t i=0; i!=N; ++i) {
                int temp; cin>>temp;
                this->data.push_back(temp);
            }
        }
        int singleNumber(vector<int>& nums) {
            map<int,int> U;
            for(vector<int>::iterator v=nums.begin(); v!=nums.end(); ++v) {
                if(U.count(*v)) U[*v]++;
                else U[*v]=1;
            }
            for(map<int,int>::iterator v=U.begin(); v!=U.end(); ++v) {
                if(v->second==1) return v->first;
                else if(v->second!=3) exit(-1);
            }
            return -1;
        }
        int singleNumber(void) {
            return singleNumber(data);
        }
        Solution(){}
        Solution(vector<int>& v) { this->data=v; }
        ~Solution() {
            N=0; data.clear();
        }
};

int main(int argc, char **argv) {
    Solution sol;
    sol.read_data();
    cout<<sol.singleNumber()<<endl;
    return 0;
}
