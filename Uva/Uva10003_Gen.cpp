// note: stdc++11
#include <bits/stdc++.h>
using namespace std;
class Gen{
    private:
        vector<int> data;
        int len, cutnum;
        string filename;
        ofstream f;
    public:
        void gen(int l, int c) {
            f << l << endl;
            f << c << endl;
            data.clear();
            for(int i=1; i<l ; ++i) data.push_back(i);
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(data.begin(), data.end(), default_random_engine(seed));
            vector<int> temp(data.begin(), data.begin()+c);
            sort(temp.begin(), temp.end());
            for(int i=0; i!=c; ++i) f << temp.at(i) << ' ';
            temp.clear();
            f << endl;
        }
        Gen(const string &s) {
            f.open(s.c_str());
            this->filename = s;
        }
        ~Gen() {
            f << 0 << endl;
            f.close(); f.clear();
        }
};

int main(void) {
    const string str("testfile.txt");
    Gen generator(str);
    int testdata [][2] = {
        {100, 10},
        {1000, 50},
        {1000, 50},
        {1000, 50},
        {1000, 50},
        {1000, 50},
        {1000, 500},
        {1000, 500},
        {1000, 500},
        {10000, 980},
        {100001, 1000},
        {1000001, 1000}
    };
    int n=sizeof(testdata)/sizeof(testdata[0]);
    int T=10;
    while(T--) {
        for(int i=0; i!=n; ++i) generator.gen(testdata[i][0], testdata[i][1]);
    }
    return 0;
}
