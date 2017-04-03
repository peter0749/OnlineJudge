#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[120][120];
int dirs[4][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1} // 四個方向
};

int main(void) {
    int T;
    scanf("%d",&T); // 測資數
    while (T--) {
        int m,n;
        scanf("%d%d",&m,&n); // 陣列大小
        memset(map,0x00,sizeof(map)); // 清空陣列，不用處理舊資料的 1
        // 因為大小才 <= 100 ，不太影響執行時間
        for(int i=1; i<=m; ++i) { 
            // 因為後面要判斷上下左右，若從 0, 0 開始存放
            // 可能會擔心超界的問題，所以直接從 1, 1 開始
            for(int j=1; j<=n; ++j) {
                int pix;
                scanf("%d",&pix);
                map[i][j] = pix;  // 讀入每個值，放到陣列裡
            }
        }
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                int check=0;
                if (map[i][j]==1) { // 遇到 1 檢查
                    for(int k=0; k<4; ++k) { // 看看上下左右有沒有 0
                        if (map[i+dirs[k][0]][j+dirs[k][1]]==0) {
                            check = 1; // 若有，代表我們找到一個邊界
                            break;
                        }
                    }
                }
                printf(check?"0 ":"_ "); // 若有找到，輸出 0 沒有輸出 _ 
            }
            puts(""); // 換行
        }
        if(T) puts(""); 
        // 若 T > 0 , 判斷式為真，會印出空行，若 T == 0 ，代表已經到最後一筆，不需輸出換行
    }
    return 0;
}
