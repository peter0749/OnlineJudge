#include <stdio.h>
#include <stdlib.h>
int main(void){
	int i,j,x,y;
	while(scanf("%d %d",&i,&j)!=EOF){
		int array[i][j];
		for(x=0;x<i;x++){
			for(y=0;y<j;y++){
				scanf("%d",&array[x][y]);
			}
		}
		for(x=0;x<j;x++){
			for(y=0;y<i;y++){
				if(y==0){
					printf("%d",array[y][x]);
				}
				else	printf(" %d",array[y][x]);
			}
			printf("\n");
		}
	}
	return 0;
}
