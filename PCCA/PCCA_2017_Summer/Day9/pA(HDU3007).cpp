/*
 * 梯度下降法
 *
 */


#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

vector< pair<double,double> > cord;

inline double l2(double x, double y) {
    double maxv = 0;
    for (vector< pair<double,double> >::iterator v=cord.begin(); v!=cord.end(); ++v) {
        double dx = v->first-x;
        double dy = v->second-y;
        maxv = max(maxv, dx*dx+dy*dy);
    }
    return maxv; 
}

inline double l1(double x, double y) {
    double maxv = 0;
    for (vector< pair<double,double> >::iterator v=cord.begin(); v!=cord.end(); ++v) {
        double dx = v->first-x;
        double dy = v->second-y;
        maxv = max(maxv, sqrt(dx*dx+dy*dy));
    }
    return maxv; 
}

pair< pair<double, double> , double> brute(int ite, int early_stop=1e9) {
    double initx, inity;
    double eps = 1;
    //double eps = 1e-3;
    double momentum = 0.9;
    double delta = 0.95;
    //double delta = 1;
    //int idx = cord.size()/2;
    //initx = cord[idx].first;
    //inity = cord[idx].second;
    initx = ((double)rand()*2e10/(double)RAND_MAX)-1e10;
    inity = ((double)rand()*2e10/(double)RAND_MAX)-1e10;

    double ori=1e9;
    double min_loss = ori;
    int not_improved = 0;
    for (int i=0; i<ite && not_improved<early_stop; ++i) {
        //cout << fixed << setprecision(2) << initx << ' ' << inity << ' ' << ori << endl;
        eps*=delta;
        ori= l2(initx, inity);
        if (ori < min_loss) {
            min_loss = ori;
            not_improved = 0;
        } else {
            ++not_improved;
        }
        double tx = l2(initx+eps, inity);
        double ty = l2(initx, inity+eps);
        initx+=(ori-tx)*momentum;
        inity+=(ori-ty)*momentum;
    }
    return make_pair( make_pair(initx, inity), l1(initx,inity));
}

#define RL() fgets(buff, 4000, stdin)

int main(void) {
    srand(time(NULL));
    int N;
    char buff[4096];
    while((RL())!=NULL) {
        sscanf(buff, "%d", &N);
        if (N==0) break;
        cord.clear();
        for (int i=0; i<N; ++i) {
            double x, y;
            RL();
            sscanf(buff,"%lf%lf", &x, &y);
            cord.push_back(make_pair(x,y));
        }
        pair< pair<double,double> , double> res = brute(1010, 200);
        printf("%.2lf %.2lf %.2lf\n" , res.first.first, res.first.second, res.second);
    }

    return 0;
}

/* 
 * 隨機增量法
 *
 */

#include <cmath>
#include <complex>
#include <valarray>
#include <functional>

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
            return std::sqrt(a.x*a.x + a.y*a.y);
        }
        static const T L2(const GeoVec &a) {
            return (a.x*a.x + a.y*a.y);
        }
        const GeoVec rot(T rad) const {
            using std::cos;
            using std::sin;
            return GeoVec(cos(rad)*x-sin(rad)*y, sin(rad)*x+cos(rad)*y);
        }
        const GeoVec unitVec(void) const { return (*this/(L1(*this))); }
        const GeoVec tVec(void) const { return GeoVec(-y, x); }
        const T cross(const GeoVec &v) {
            return (this->x*v.y - this->y*v.x);
        }
        // 點向式
        // 從 Line: sx,sy 射出的向量 v , dot: x, y
        double dot2Line(T x, T y, T sx, T sy, const GeoVec &v) {
            GeoVec u(x-sx, y-sy);
            // 向量 sx, sy 射出的向量到 x, y
            T cross = v.cross(u);
            // v x u 得到面積
            if(cross<0) cross=-cross;
            return cross/L1(v);
            // 面積 / 底 = 高（點到直線距離）
        }
        // 求 a1xb1y+c1=0, a2xb2y+c2=0 交點
        static GeoVec twoLineSec(T a1, T b1, T c1, T a2, T b2, T c2) {
            // 小心除 0
            return GeoVec((c1*a2-a1*c2) / (b1*a2-b2*a1),
                          (c1*b2-c2*b1) / (a1*b2-b1*a1));
        }
};
// all public for convenient in contest
// following are operator overloading for class template GeoVec
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
    return first.cross(second);
}

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

vector< GeoVec<double> > cord;
GeoVec<double> O;
double r;

int main(void) {
    int n;
    while(scanf("%d", &n)==1 && n) {
        for (int i=0; i<n; ++i) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            cord.push_back(GeoVec<double>(x, y));
        }
        random_shuffle(cord.begin(), cord.end());
        O = cord[0]; r=0.0;
        for (int i=1; i<cord.size(); ++i) {
            if (GeoVec<double>::L2(cord[i]-O) > r*r + 1e-7) {
                O = cord[i]; r = 0.0;
                for (int j=0; j<i; ++j) {
                    if (GeoVec<double>::L2(cord[j]-O) > r*r + 1e-7) {
                        O = GeoVec<double>(cord[i]+cord[j])/2.0;
                        r = GeoVec<double>::L1(cord[j]-O);
                        for (int k=0; k<j; ++k) {
                            if (GeoVec<double>::L2(cord[k]-O) > r*r + 1e-7) {
                                // 求外心
                                O = GeoVec<double>::twoLineSec(
                                        cord[j].x-cord[i].x,
                                        cord[j].y-cord[i].y,
                                        ( cord[j].L2(cord[j]) - cord[i].L2(cord[i]) ) / 2.0,
                                        cord[k].x-cord[i].x,
                                        cord[k].y-cord[i].y,
                                        ( cord[k].L2(cord[k]) - cord[i].L2(cord[i]) ) / 2.0
                                    );
                                r = GeoVec<double>::L1(O-cord[k]);
                            }
                        }
                    }
                }
            }
        }
        printf("%.2lf %.2lf %.2lf\n", O.x, O.y, r);
        cord.clear(); // cleanup
    }
}
