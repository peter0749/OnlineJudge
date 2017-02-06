#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#define MAXN 50
using namespace std;

char book[MAXN][MAXN];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int step_c;

void dfs( int y, int x )
{
	int ny, nx;
	for(int i=0; i<4; ++i)
	{
		ny = y+dir[i][0];
		nx = x+dir[i][1];
		if( book[ny][nx]=='.' && book[ny][nx]!=0 )
		{
			step_c++;
			book[ny][nx] = 0;
			dfs(ny,nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	int W, H, x, y;
	while(cin>>W>>H && W && H)
	{
		memset(book,0x00,sizeof(book));
		for(int i=1; i<=H; ++i )
		{
			for(int j=1; j<=W; ++j) 
			{
				cin>>book[i][j];
				if(book[i][j]=='@'){
					y = i; x = j;
				}
			}
		}
		step_c = 1;
		dfs(y,x);
		cout<<step_c<<'\n';
	}
	return 0;
}
