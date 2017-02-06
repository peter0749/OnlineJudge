#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#define MAXN 400
#define INF 1000000009
#define MP make_pair
using namespace std;
typedef pair<int, pair<int,int> > ELE; //step, y, x;
queue< ELE > que;
int book[MAXN][MAXN];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main(void)
{
    ios::sync_with_stdio(false);
    int M, y, x, t, ny, nx;
    bool suc;
    ELE ele;
    while(cin>>M && M)
    {
        for(int i=0; i<MAXN; ++i)for(int j=0; j<MAXN; ++j) book[i][j] = INF;
        for(int i=0; i<M; ++i)
        {
            cin>>x>>y>>t;
            x++; y++;
            book[y][x] = min(book[y][x], t);
            for(int j=0; j<4; ++j) book[y+dir[j][0]][x+dir[j][1]] = min(book[y+dir[j][0]][x+dir[j][1]], t);
        }
        suc = false;
        que.push( MP(0,MP(1,1)) );
        while(!que.empty() && !suc)
        {
            ele = que.front(); que.pop();
            for(int i=0; i<4; ++i)
            {
                ny = ele.second.first + dir[i][0];
                nx = ele.second.second + dir[i][1];
                if(ny<=0 || ny>=MAXN-1 || nx<=0 || nx>=MAXN-1) continue;
                if( ele.first+1 >= book[ny][nx] ) continue;
                if( book[ny][nx]==INF )
                {
                    //cout<<'#'<<ny<<' '<<nx<<endl;
                    suc = true;
                    break;
                }
                book[ny][nx] = -1;
                que.push( MP(ele.first+1, MP(ny,nx)) );
            }
        }
        while(!que.empty()) {que.pop();}
        cout<< (suc?ele.first+1:-1) <<'\n';
    }
    return 0;
}
