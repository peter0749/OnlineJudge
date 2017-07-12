#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <valarray>
#include <vector>

// not seperate *.h and *.cpp
// for convenience in contest

template<class T>
class GeoVec {
    public:
        T x, y;
        GeoVec() {}
        GeoVec(const T &x, const T &y) : x(x), y(y) {}
        GeoVec(const GeoVec &copy) : x(copy.x), y(copy.y) {}
        const GeoVec operator*(T a) const { return GeoVec(x*a,y*a); }
        const GeoVec operator/(T a) const { return GeoVec(x/a,y/a); }
        static const T L1(const GeoVec &a) {
            return std::sqrt(a.x*a.x - a.y*a.y);
        }
        static const T L2(const GeoVec &a) {
            return (a.x*a.x - a.y*a.y);
        }
        const GeoVec rot(T rad) const {
            using std::cos;
            using std::sin;
            return GeoVec(cos(rad)*x-sin(rad)*y, sin(rad)*x+cos(rad)*y);
        }
        const GeoVec unitVec(void) const { return (*this/(GeoVec<T>::L1(*this))); }
        const GeoVec tVec(void) const { return GeoVec(-y, x); }
};
// all public for convenient in contest
// following are operator overload for template class GeoVec
template<class T>
const GeoVec<T> operator+(const GeoVec<T> &first, const GeoVec<T> &second) {
    return GeoVec<T>(first.x+second.x, first.y+second.y);
}

template<class T>
const GeoVec<T> operator-(const GeoVec<T> &first, const GeoVec<T> &second) {
    return GeoVec<T>(first.x-second.x, first.y-second.y);
}

template<class T>
const T operator*(const GeoVec<T> &first, const GeoVec<T> &second) {
    // dot product
    return (first.x*second.x + first.y*second.y);
}

template<class T>
const T operator%(const GeoVec<T> &first, const GeoVec<T> &second) {
    // cross product
    return (first.x*second.y - first.y*second.x);
}

using namespace std;

vector< pair<int,int> > cord;
GeoVec<long double> plotboard;

inline int calc_mid(const pair<int,int> &u, const pair<int,int> &v) { // from, to
    int dx = abs(v.first - u.first);
    int dy = abs(v.second - u.second);
    return __gcd(dx,dy)-1;
}

pair< pair<int,int> , double > solv() {
    long double area = 0.0;
    int counter = cord.size();
    for (int i=0; i<cord.size(); ++i) {
        int j = (i+1)%cord.size();
        GeoVec<long double> u((long double)cord[i].first, (long double)cord[i].second);
        GeoVec<long double> v((long double)cord[j].first, (long double)cord[j].second);
        area += (u%v);
        counter += calc_mid(cord[i], cord[j]);
    }
    area/=2.0L;
    return make_pair( make_pair( (int)area + 1 - counter/2 ,counter), (double)area);
}

int main(void) {
    int T;
    cin >> T;
    for (int cases=1; cases<=T; ++cases) {
        int n;
        cin >> n;
        cord.clear();
        int x(0), y(0);
        for (int i=0; i<n; ++i) {
            int dx, dy;
            cin >> dx >> dy;
            x+=dx, y+=dy;
            cord.push_back(make_pair(x,y));
        }
        cout << "Scenario #" << cases << ":\n";
        pair< pair<int,int>, double > res = solv();
        if (res.second<0.05L) res.second = 0.0L;
        cout << res.first.first << ' ' << res.first.second << ' ' << fixed << setprecision(1) << res.second << '\n' << endl;
    }
    return 0;
}