#include <iostream>
#include <vector>

using namespace std;

const int dx[16] = { 0, 1, 2, 3, 3, 3, 2, 1, 0, -1, -2, -3, -3, -3, -2, -1 };
const int dy[16] = { -3, -3, -2, -1, 0, 1, 2, 3, 3, 3, 2, 1, 0, -1, -2, -3};

inline bool isCorner(int i, int j, const vector<vector<int> > &bitmap) {
    int N=bitmap.size(), M=bitmap[0].size();
    if (i<3 || i>=N-3 || j<3 || j>=M-3)
        return false;
    int cnt = 1;
    int max_cnt = 1;
    for (int k=0; k<32; ++k) {
        if (bitmap[i+dy[k&15]][j+dx[k&15]] == bitmap[i+dy[(k+1)&15]][j+dx[(k+1)&15]])
            ++cnt;
        else
            cnt = 1;
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt >= 12;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int T = 0;
    while(cin >> N >> M) {
        vector<vector<int> > bitmap(N, vector<int>(M, 0));
        for (int i=0; i<N; ++i) {
            string s;
            cin >> s;
            for (int j=0; j<M; ++j)
                bitmap[i][j] = s[j]-'0';
        }
        ++T;
        cout << "Case #" << T << ":\n";
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                cout << (isCorner(i,j,bitmap)?'1':'0');
            }
            cout << "\n";
        }
    }
    return 0;
}
