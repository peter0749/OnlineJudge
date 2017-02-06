#include <bits/stdc++.h>
#define MAX 110
#define START 1
#define INTMIN -2147483648

using namespace std;
int DP[MAX];

inline int M(const int a, const int b)
{
	return a>b?a:b;
}

inline int F(int i, const int data[], const int n)
{
	if(DP[i]!=INTMIN)return DP[i];
	return DP[i] = M(F(i-1,data,n)+data[i],data[i]);
}

int main(void)
{
	int arr[MAX];
	int term;
	int n, i;
	int maxval=INTMIN;
	int val;
	cin.sync_with_stdio(false);
	cin>>term;
	while(term--)
	{
		cin>>n;
		for(i=0; i<n; i++)DP[i]=INTMIN;
		for(i=0; i<n; i++)
			cin>>arr[i];
		maxval = DP[0] = arr[0];
		for(i=START; i<n; i++)
		{
			val = F(i,arr,n);
			if(val>maxval)maxval=val;
		}
		cout<<maxval<<'\n';
	}
	return 0;
}
