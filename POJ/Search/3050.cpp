#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#define GSIZE 5
#define STKTOP 6
using namespace std;

const int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int book[GSIZE*2][GSIZE*2];
int crr_stk[STKTOP*2];
int counter;
set<string> C;

void dfs(int y, int x, int crr_d)
{
	int nx, ny;
	//if(crr_stk[crr_d]>book[y][x]) return;
	if(crr_d==STKTOP){
		string ss;
		for(int i=0; i<6; ++i){
			ss.push_back(crr_stk[i]);
		}
		C.insert(ss);
		return;
	}
	crr_stk[crr_d] = book[y][x];
	for(int i=0; i<4; ++i){
		ny = y+dir[i][0];
		nx = x+dir[i][1];
		if(ny>=0 && ny<GSIZE && nx>=0 && nx<GSIZE){
			dfs(ny,nx,crr_d+1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	while(1)
	{
		for(int i=0; i<GSIZE; ++i){
			for(int j=0; j<GSIZE; ++j){
				if( !(cin>>book[i][j]) ) return 0;
			}
		}
		for(int i=0; i<STKTOP;++i) crr_stk[i]=-2;
		counter = 0;
		C.clear();
		for(int i=0; i<GSIZE; ++i){
			for(int j=0; j<GSIZE; ++j){
				dfs(i,j,0);
			}
		}
		cout<<C.size()<<'\n';
	}
	return 0;
}
