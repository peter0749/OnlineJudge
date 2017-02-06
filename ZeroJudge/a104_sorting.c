#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1010

void real_sort(const int left, const int right, char *ptr, const size_t block, const size_t word_len, int (*cmp)(const void *, const void *))
{
    if(left>=right)return;/*The size of partition <= 0, exit.*/
    int i, j, rd_m;
    char *temp;
    temp = (char*)malloc(word_len);/*Allocate temporary variable.*/
    #if 0
    if( right - left == 1 ) //If there are only 2 elements, no sorting is needed.
    {
        if( cmp(ptr+left*block, ptr+right*block) > 0 )
        {
            memcpy(temp, ptr+left*block, word_len);
            memcpy(ptr+left*block, ptr+right*block, word_len);
            memcpy(ptr+right*block, temp, word_len);
        }
        free(temp);
        return;
    }
    #endif
    rd_m = left + (((int)rand())%(right-left+1)); //Get random pivot

    //printf("%d %d %d\n",left,rd_m,right);
    memcpy(temp, ptr+rd_m*block, word_len);//random pivot? Move from rd_m to leftmost.
    memcpy(ptr+rd_m*block, ptr+left*block, word_len);
    memcpy(ptr+left*block,temp,word_len);
    /*begin to partition.*/
    i = left;
    j = right+1;
    do
    {
        do{i++;}while( cmp( ptr+block*i, ptr+block*left ) < 0 );//Find bigger than pivot
        do{j--;}while( cmp( ptr+block*j, ptr+block*left ) > 0 );//Find smaller than pivot
        if(i<j)
        {
            /*Swap it.*/
            memcpy(temp, ptr+block*i, word_len);
            memcpy(ptr+block*i, ptr+block*j, word_len);
            memcpy(ptr+block*j, temp, word_len);
        }
    }while(i<j);
    memcpy(temp, ptr+block*j, word_len);
    memcpy(ptr+block*j, ptr+block*left, word_len);
    memcpy(ptr+block*left, temp, word_len);
    free(temp); temp=NULL;
    /*End of partition.*/
    real_sort(left, j-1, ptr, block, word_len, cmp);
    real_sort(j+1, right, ptr, block, word_len, cmp);
}

void my_qsort(void *ptr, size_t n, size_t word_len, int (*cmp)(const void *, const void *))
{
    //Initialize random seed;
    srand((unsigned int)time(NULL));
    //srand(7);
    //printf("%d\n",word_len);
    //printf("%d\n",word_len/sizeof(char));
    real_sort(0, n-1, (char*)ptr, (word_len/sizeof(char)), word_len, cmp);//All cast to char;
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n, i;
    int arr[MAX];
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d", arr+i);
        qsort(arr,n,sizeof(int),cmp);
        printf("%d",arr[0]);
        for(i=1; i<n; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
