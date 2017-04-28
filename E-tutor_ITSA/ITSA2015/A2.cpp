#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int M,N, X1, X2, Y1, Y2;
int N1, N2, E1, E2;
int F1, F2;
int Timer;

void bot1() {
    if (Timer>=F1) return;
    if (Timer%(N1+E1)<N1) {
        ++Y1;
    } else {
        ++X1;
    }
    X1%=M;
    Y1%=N;
}

void bot2() {
    if (Timer>=F2) return;
    if (Timer%(N2+E2)<E2) {
        ++X2;
    } else {
        ++Y2;
    }
    X2%=M;
    Y2%=N;
}

bool boom() {
    return (X1==X2 && Y1==Y2);
}

bool bot_terminate() {
    return (Timer>=F1 && Timer>=F2);
}

int main(void) {
    int T;
    //ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        Timer=0;
        cin >> M >>  N >>  X1 >>  Y1 >>  E1 >>  N1 >>  F1 >>  X2 >>  Y2 >>  E2 >>  N2 >>  F2;
        for(;;) {
            if (boom()) {
                cout << "robots explode at time " << Timer << endl;
                break;
            } else if (bot_terminate()) {
                cout << "robots will not explode" << endl;
                break;
            }
            bot1(); bot2(); ++Timer;
        }
    }
    return 0;
}
