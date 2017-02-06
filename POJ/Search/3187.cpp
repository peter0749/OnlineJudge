#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 20
using namespace std;

const int coef[MAXN][MAXN]
={
{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1},{1,6,15,20,15,6,1},\
{1,7,21,35,35,21,7,1},{1,8,28,56,70,56,28,8,1},{1,9,36,84,126,126,84,36,9,1}
};
int arr[MAXN];

int main(void){
	ios::sync_with_stdio(false);
	int n, m, sumv;
	while(cin>>n>>m){
		for(int i=0; i<n; ++i) arr[i] = i+1;
		do{
			sumv = 0;
			for(int i=0; i<n; ++i) sumv += (arr[i]*coef[n-1][i]);
		}while( sumv!=m && next_permutation(arr,arr+n));
		cout<<arr[0];
		for(int i=1; i<n; ++i){
			cout<<' '<<arr[i];
		}
		cout<<'\n';
	}
	return 0;
}
