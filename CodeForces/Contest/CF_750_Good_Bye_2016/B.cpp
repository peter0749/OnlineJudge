#include <bits/stdc++.h>
#define PB push_back
#define X first
#define Y second
#define MAXN 10000
#define DIS 40000
using namespace std;
typedef pair< int, int > PII;
typedef vector< int > VEC;

int main(void) {
    int N;
    int y=20000, dist;
    char temp[1000], dir[1000];
    bool flag=true;
    fgets(temp, sizeof(temp), stdin);
    N = atoi(temp);
    while(N--) {
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d %s", &dist, dir);
        if(flag){
            switch(dir[0]) {
                case 'N':
                    if(y==20000||dist>(y>20000?60000-y:20000-y)) flag=false;
                    y=(y+dist)%DIS;
                    break;
                case 'S':
                    if(y==0||dist>y) flag=false;
                    y=(y-dist+DIS*100)%DIS;
                    break;
                default:
                    if(y==0||y==20000) flag=false;
                    break;
            }
        }
    }
    printf(flag&&y==20000? "YES\n":"NO\n");
    return 0;
}
