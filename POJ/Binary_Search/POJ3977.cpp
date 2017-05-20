#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

// 狀態 ~2^18 以下
const size_t MAX_SET(300000);
// 範圍 ~ 10^15 ，記得開 long long
const long long int Inf(9023372036854775807L);
pair<long long int, long long int> Left[MAX_SET], Right[MAX_SET];
long long int input[40], N;
long long int minN, minV;

// 注意： std::abs(long long int) => C++11
inline long long int Abs(long long int a) {
    return a<0L?-a:a;
}

void init(void) {
    fill(Left, Left+MAX_SET, make_pair(0L,0L));
    fill(Right, Right+MAX_SET, make_pair(0L,0L));
    minN=minV=Inf;
}

void getSet(int l, int n, pair<long long int,long long int> *ptr) {
    for (int i=0; i<(1<<n); ++i) {
        for (int j=0; j<n; ++j) {
            if ((i>>j)&1) {
                ptr[i].first+=input[l+j];
                ptr[i].second++;
            }
        }
        if (ptr[i].second!=0) {
            // 一邊做左右邊，
            // 一邊更新答案。
            long long int temp = Abs(ptr[i].first);
            if(temp<=minV) {
                if(temp<minV) minN=ptr[i].second;
                else minN=min(minN,ptr[i].second); //temp==minv
                minV=temp;
            }
        } else {
            ptr[i].second  = ptr[i].first = Inf; // mark for delete, 當作陣列裡的衛兵
        }
    }
}

void solv(void) {
    int M=N/2;
    int lN = M;
    int rN = N-M;
    init();
    getSet(0, lN, Left); // check left
    getSet(M, rN, Right); // check right
    sort(Left, Left+(1<<lN));
    for (int i=0; i<1<<rN; ++i) { // check left + right
        long long int num = Right[i].second;
        if (num==Inf) continue; // empty
        int idv = lower_bound(Left, Left+(1<<lN), make_pair(-Right[i].first, (long long int)-1L)) - Left;
        // !!注意邊界!! 尋找最接近 -Right 的 Left 值
        long long int temp = Abs(Left[idv].first+Right[i].first); // 自己
        int t = idv;
        if (t>0 && Abs(Left[t-1].first+Right[i].first)<temp) { // 左邊
            idv = t-1;
            temp = Abs(Left[idv].first+Right[i].first);
        }
        if (Abs(Left[t+1].first+Right[i].first)<temp) { // 右邊，最右邊有站一個衛兵，所以不用邊街判斷
            idv = t+1;
            temp = Abs(Left[idv].first+Right[i].first);
        }
        if (Left[idv].second==Inf) continue; // 非法
        num += Left[idv].second; // 更新左右合併的解
        if (temp<=minV) { // 更新答案
            if (temp<minV) minN=num;
            else minN=min(minN,num);
            minV = temp;
        }
    }
    printf("%lld %lld\n",minV, minN);
}

bool IO(void) {
    scanf("%lld",&N);
    if (N==0) return false;
    for (int i=0; i<N; ++i) scanf("%lld",input+i);
    return true;
}

int main(void) {
    while(IO()) {
        if (N==1L) {
            printf("%lld 1\n", Abs(input[0]));
            continue;
        }
        solv();
    }
    return 0;
}
