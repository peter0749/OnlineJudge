#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, K;
int dir[5100]; // Front, Back
bool flip[5100]; // flipped or not

// f[i] = f[i] - f[i-k+1]

int testK(int k) {
    // check all f ~ f[i]
    int sum = 0;
    int res = 0; // times of flipping
    memset(flip,0x00,sizeof(bool)*(N+1));
    for (int i=0; i<=N-k; ++i) {
        if ((sum+dir[i])%2) { // needs flip
            flip[i]=1;
            ++res;
        }
        sum += flip[i];
        if (i-k+1>=0) {
            sum -= flip[i-k+1];
        }
    }
    for (int i=N-k+1; i<=N; ++i) {
        if ((sum+dir[i])%2) return -1;
        if (i-k+1>=0) sum-= flip[i-k+1];
    }
    return res;
}

void solv(void) {
    K = 1, M = N;
    for (int i=1; i<=N; ++i) {
        int m = testK(i);
        if (m>=0 && m<M) {
            M = m, K = i;
        }
    }
    cout << K << ' ' << M << '\n';
}

void Input(void) {
    cin >> N;
    for (int i=0; i<N; ++i) {
        char temp; cin >> temp;
        dir[i] = (temp=='F'?0:1);
    }
    dir[N]=0;
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    Input();
    solv();
    return 0;
}
