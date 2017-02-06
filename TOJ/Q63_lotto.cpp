#include <bits/stdc++.h>
#define MAXLEN 6
#define ARRSIZE 15

using namespace std;

int lotto[MAXLEN];
int mystk[ARRSIZE];

inline void prtout(void)
{
	cout<<mystk[0];
	for(int i=1; i<MAXLEN; i++)	cout<<' '<<mystk[i];
	cout<<'\n';
}

inline void dfs(int last, int depth, const int poolsize)
{
	if(depth==MAXLEN)	prtout();
	else
	{
		for(int i=last+1; i<poolsize; i++)
		{
			mystk[depth] = lotto[i];
			dfs(i,depth+1,poolsize);
		}
	}
}

int main(void)
{
	cout.sync_with_stdio(false);
	int term;
	int first(1);
	//freopen("testout.txt","w",stdout);
	while(cin>>term)
	{
		if(term==0) break;
		if(first)first=0;
		else cout<<'\n';
		for(int i=0; i<term; i++)	cin>>lotto[i];
		dfs(-1,0,term);
	}
	return 0;
}
