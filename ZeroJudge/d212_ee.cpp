#include <iostream>
#define MAX 100
#define UDET 4
using namespace std;

unsigned long int DP[MAX]={0,1,2,3};

inline unsigned long int F(int n)
{
	if(DP[n]>0)return DP[n];
	return DP[n] = DP[n-1] + DP[n-2];
}

int main(void)
{
	cin.sync_with_stdio(false);
	unsigned short n;
	for(char i=UDET; i<MAX; i++)F(i);
	while(cin>>n)
	{
		cout<<DP[n]<<'\n';
	}
	return 0;
}
