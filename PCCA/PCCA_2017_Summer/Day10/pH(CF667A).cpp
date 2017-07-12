#pragma GCC optimize ("O0")
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <valarray>
#include <vector>
using namespace std;

int main(void) {
    long double d,h,v,e;
    cin >> d >> h >> v >> e;
    long double bottom = d/2.0L;
    bottom *= bottom*M_PI;
    long double dV = v - e*bottom;
    if (dV<1e-8L) cout << "NO" << endl;
    else cout << "YES\n" << fixed << setprecision(7) << (h*bottom / dV) << endl; 
}