#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
int arr[MAX];

int cmp(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

int main(void) {
    int n, i;
    while(scanf("%d", &n)!=EOF) {
        for(i=0; i<n; i++)scanf("%d", arr+i);
        qsort(arr,n,sizeof(int),cmp);
        printf("%d",arr[0]);
        for(i=1; i<n; i++)printf(" %d",arr[i]);
        printf("\n");
    }
    return 0;
}
