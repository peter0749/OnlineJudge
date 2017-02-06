#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char str[1000];
		int i,strlenm1;
		while(scanf("%s",&str)!=EOF){
			int same=1;
			strlenm1=strlen(str)-1;
			for(i=0;i<=(strlenm1)/2;i++){
				if(str[i]!=str[strlenm1-i]){
					same=0;
					break;
				}
			}
			if(same==1)	printf("yes\n");
			else	printf("no\n");
			
		}
	return 0;
}
