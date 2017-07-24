#include <bits/stdc++.h>
using namespace std;

int lumH[300];
int lumR[300];
int lumG[300];
int lumB[300];

int main(void) {
    int w, h;
    memset(lumH, 0x00, sizeof(lumH));
    memset(lumR, 0x00, sizeof(lumR));
    memset(lumG, 0x00, sizeof(lumG));
    memset(lumB, 0x00, sizeof(lumB));
    cin >> w >> h;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
        int r, g, b;
        cin >> r >> g >> b;
        int lum = round((r+g+b)/3.0);
        ++lumH[lum];
        ++lumR[r];
        ++lumG[g];
        ++lumB[b];
    }
#define HIST(hist) { \
    cout << hist[0]; \
    for (int i=1; i<256; ++i) \
        cout << ' ' << hist[i]; \
    cout << endl; }

    HIST(lumR);
    HIST(lumG);
    HIST(lumB);
    HIST(lumH);
    return 0;
}
