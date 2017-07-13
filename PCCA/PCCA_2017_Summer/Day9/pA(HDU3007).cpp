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
#include <complex>
#include <valarray>

using namespace std;

typedef pair<double,double> PII;
#define X first
#define Y second
vector< PII > cord;

double crossP(PII &o, PII &a, PII &b) {
    return (a.X - o.X) * (b.Y-o.Y) - \
           (a.Y - o.Y) * (b.X-o.X);
}

void Andrew_removeInnerPoints(void) {
    vector< PII > convex_hull;
    sort(cord.begin(), cord.end());
    for (int i=0; i<cord.size(); ++i) {
        while(convex_hull.size()>=2 && crossP(convex_hull[convex_hull.size()-2], convex_hull[convex_hull.size()-1], cord[i]) <= 0.0 ) convex_hull.pop_back();
        convex_hull.push_back(cord[i]);
    }
    for (int i=cord.size()-2, t=convex_hull.size()+1; i>=0; --i) {
        while(convex_hull.size()>=t && crossP(convex_hull[convex_hull.size()-2], convex_hull[convex_hull.size()-1], cord[i]) <= 0.0 ) convex_hull.pop_back();
        convex_hull.push_back(cord[i]);
    }
    convex_hull.pop_back();
    cord.clear();
    cord.reserve(convex_hull.size());
    cord = convex_hull;
    convex_hull.clear();
}

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
    double momentum = 0.9;
    double delta = 0.95;
    //double delta = 1;
    int idx = cord.size()/2;
    initx = cord[idx].first;
    inity = cord[idx].second;
    //initx = ((double)rand()*2e10/(double)RAND_MAX)-1e10;
    //inity = ((double)rand()*2e10/(double)RAND_MAX)-1e10;

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
        if (N>10)
            Andrew_removeInnerPoints();
        pair< pair<double,double> , double> res = brute(2001);
        if (abs(res.first.first)<0.005) res.first.first = 0.0;
        if (abs(res.first.second)<0.005) res.first.second = 0.0;
        if (abs(res.second)<0.005) res.second = 0.0;
        printf("%.2f %.2f %.2f\n" , res.first.first, res.first.second, res.second);
    }

    return 0;
}
