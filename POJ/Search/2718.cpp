#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
int arr[100];

inline int to_int(int l, int r)
{
	int temp=0;
	for(int i=l; i<=r; ++i)
	{
		temp*=10;
		temp+=arr[i];
	}
	return temp;
}

int main(void)
{
	int term, n, m, t, i, j;
	char temp[1000], *ptr;
	char t1[1000], t2[1000];
	int n1, n2, minval;
	const char *tok=" \t";
	fgets(temp,sizeof(temp),stdin);
	term = atoi(temp);
	while(term--)
	{
		n = 0;
		minval = INT_MAX;
		fgets(temp,sizeof(temp),stdin);
		ptr = strtok(temp,tok);
		while(ptr!=NULL)
		{
			arr[n++] = atoi(ptr);
			ptr = strtok(NULL,tok);
		}
		m = n>>1;
		if(arr[0]==0){
			swap(arr[0],arr[1]);
		}
		do{
			if( m<n-1 && arr[m]==0){
				swap(arr[m],arr[m+1]);
			}
			n1 = to_int(0,m-1);
			n2 = to_int(m,n-1);
			minval = min(minval,abs(n1-n2));
		}while(next_permutation(arr,arr+n));
		printf("%d\n",minval);
	}
	return 0;
}
