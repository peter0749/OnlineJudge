#include <bits/stdc++.h>
#define MAXN 103
using namespace std;

int nums[MAXN];

inline int get_hamm( const int &a, const int &b)
{
	int counter=0;
	int temp = a^b;
	while(temp)
	{
		counter += (temp&1);
		temp>>=1;
	}
	return counter;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int T, N;
	int maxval, sum;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++) cin>>nums[i];
		maxval = 0;
		for(int i=0; i<N; i++)
		{
			for(int j=i+1; j<N; j++)
			{
				sum = get_hamm(nums[i], nums[j]);
				maxval = max(maxval, sum);
			}
		}
		cout<<maxval<<'\n';
	}
	return 0;
}
