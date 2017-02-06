#include <bits/stdc++.h>
#define STRL 200000
#define P 32416190071uLL
using namespace std;
typedef unsigned long long int ULLD;

map<string,int> M;

int main(void)
{
	ios::sync_with_stdio(false);
	pair< map<string,int>::iterator, bool> ite;
	string str;
	int N;
	cin>>N;
	while(N--)
	{
		cin>>str;
		ite = M.insert(make_pair(str,0));
		if(ite.second) cout<<"OK\n";
		else
		{
			M[str]++;
			cout<<str<<M[str]<<'\n';
		}
	}
	
	return 0;
}
