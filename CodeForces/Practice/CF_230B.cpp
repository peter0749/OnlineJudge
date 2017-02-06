#include <bits/stdc++.h>
#define MAXN 10010
#define MAXP 1000005
using namespace std;

char prime[1000010];

inline bool mk_prime(void)
{
	int i, j;
	memset(prime,0x00,sizeof(prime));
	for(i=3; i<MAXP; i+=2)
	{
		if(!prime[i])//==0
		{
			for(j=i+i; j<MAXP; j+=i)
				prime[j] = true;
		}
	}
}

inline bool is_prime(long long int n)
{
	if(n==2) return true;
	else if(n&1uLL)//Not even
	{
		return !prime[n];
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int num, temp;
	int N;
	mk_prime();
	cin>>N;
	while(N--)
	{
		cin>>num;
		if(num==1)
		{
			cout<<"NO\n";
			continue;
		}
		temp = (long long int)sqrtl((long double)num);
		if(temp*temp == num && is_prime(temp)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
