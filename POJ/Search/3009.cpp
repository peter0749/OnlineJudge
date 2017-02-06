#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXD 30
using namespace std;
int book[MAXD][MAXD];
int starts[2], endn[2];//y,x
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans;

void dfs(int y, int x, int dep){
	int ny, nx;
	if(dep == 10) return;
	//cout<<y<<' '<<x<<endl;
	//getchar();
	for(int i=0; i<4; ++i)
	{
		ny = y+dir[i][0];
		nx = x+dir[i][1];
		if( book[ny][nx]==3 )
		{
			ans = min(ans,dep+1);
			//cout<<dep+1<<endl;
			return;
		}
		else if( book[ny][nx]==0 || book[ny][nx]==2 )
		{
			int nny=ny+dir[i][0], nnx=nx+dir[i][1];
			while(book[nny][nnx]==0){ ny=nny; nx=nnx; nny+=dir[i][0]; nnx+=dir[i][1] ;}
			if(book[nny][nnx]==3)
			{
				ans = min(ans,dep+1);
				//cout<<dep+1<<endl;
				return;
			}
			else if(book[nny][nnx]==1)
			{
				book[nny][nnx] = 0;
				dfs(ny,nx,dep+1);
				book[nny][nnx] = 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	int W, H;
	while(cin>>W>>H && W && H)
	{
		memset(book,-1,sizeof(book));
		for(int i=1; i<=H; ++i)
		{
			for(int j=1; j<=W; ++j)
			{
				cin>>book[i][j];
				if(book[i][j]==2) { starts[0]=i; starts[1]=j; book[i][j]=0; }
				else if(book[i][j]==3) { endn[0]=i; endn[1]=j; }
			}
		}
		
		ans = 100;
		dfs(starts[0],starts[1],0);
		ans = (ans==100)?-1:ans;
		cout<<ans<<'\n';
	}
	return 0;
}
