#include <stdio.h>
int main(){
	int t,i,j,test2[3];
	float test1[3];
	while(scanf("%d",&t)!=EOF){
		int input[t][4];
		int ans[t][5];
		for(i=0;i<t;i++){
				scanf("%d %d %d %d",&input[i][0],&input[i][1],&input[i][2],&input[i][3]);
				
		}
		for(i=0;i<t;i++){
			for(j=0;j<3;j++){
				test1[j]=(float)(input[i][j+1]/input[i][j]);
				
				test2[j]=(input[i][j+1]-input[i][j]);
				
			}
			if(test1[0]==test1[1] && test1[1]==test1[2]){
				for(j=0;j<4;j++){
					ans[i][j]=input[i][j];
				}
				ans[i][4]=test1[0]*input[i][3]; 
			}
			else if(test2[0]==test2[1] && test2[1]==test2[2]){
				for(j=0;j<4;j++){
					ans[i][j]=input[i][j];
				}
				ans[i][4]=test2[0]+input[i][3]; 
			}
		}
		for(i=0;i<t;i++){
			for(j=0;j<5;j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}	
	}
	return 0; 
}
