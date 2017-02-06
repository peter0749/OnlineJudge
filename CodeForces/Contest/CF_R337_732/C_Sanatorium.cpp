#include <bits/stdc++.h>
#define XLIM 1000000000010000000LL
using namespace std;
typedef long long int LLD;

int main(void)
{
	ios::sync_with_stdio(false);
	LLD b,d,s,maxval,l;
	while(cin>>b>>d>>s)
	{
		l = 0;
		maxval = max(b,max(d,s));
		if(d==maxval)
			l+=(s==d?0:d-s-1)+(b==d?0:d-b-1);
		else if(b==maxval)
			l+=(b-1-d) + (b==s?0:b-1-s);
		else
			l+=(s-1)-b+(s-1)-d;
		cout<<l<<'\n';
	}
	return 0;
}
