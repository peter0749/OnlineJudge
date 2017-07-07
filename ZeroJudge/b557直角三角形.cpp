#include <bits/stdc++.h>
using namespace std;

int arr[200];

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            scanf("%d", arr+i);
        }
        int c = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) 
                for (int k=0; k<n; ++k)
                    c += (arr[i]*arr[i]+arr[j]*arr[j] == arr[k]*arr[k]);
        printf("%d\n", c>>1);
    }
    return 0;
}
