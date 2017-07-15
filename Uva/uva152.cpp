#include <bits/stdc++.h>
using namespace std;

struct _3D {
    _3D(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
    static double dist(const _3D &u, const _3D &v) {
        double dx = u.x-v.x;
        double dy = u.y-v.y;
        double dz = u.z-v.z;
        return sqrt(dx*dx+dy*dy+dz*dz);
    }
};

vector< _3D > cord;
int hist[16];

int main(void) {
    char buff[4096];
    memset(hist,0x00,sizeof(hist));
    while((fgets(buff,4000,stdin))!=NULL) {
        int tx, ty, tz;
        sscanf(buff,"%d%d%d",&tx,&ty,&tz);
        if (!tx && !ty && !tz) break;
        double x, y, z;
        sscanf(buff,"%lf%lf%lf", &x, &y, &z);
        cord.push_back(_3D(x,y,z));
    }
    for (int i=0; i<cord.size(); ++i) {
        double min_d = 1e100;
        for (int j=0; j<cord.size(); ++j) {
            if (i==j) continue;
            min_d = min(min_d, _3D::dist(cord[i], cord[j]));
        }
        int idx = min_d;
        if (idx<10) ++hist[idx];
    }
    for (int i=0; i<10; ++i) printf("%4d", hist[i]); 
    printf("\n");
    return 0;
}
