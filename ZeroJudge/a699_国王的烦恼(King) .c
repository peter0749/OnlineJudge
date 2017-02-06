#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int bit_map[671100]={0};
void make_prime(void);
int is_prime(int);
int main(){
	int input;
	make_prime();
	/*printf("Done!\n");*/
	while(scanf("%d",&input)!=EOF){
		if(is_prime(input)==1)	printf("It's a prime!!!\n");
		else	printf("It's not a prime!!!\n");
	}
	return 0;
}
void make_prime(void){
	int i,j,index=0;
	for(i=3;i<=671099;i+=2){
		if(bit_map[i]==0){
			for(j=i+i;j<=671099;j=i+j){
				bit_map[j]=1;
			}
			
		}
	}
	
}
int is_prime(int input){
	if(input < 2)	return 0;
	else if(input==2)	return 1;
	else if(input%2==0)	return 0;
	else{
		return !bit_map[input];
	}

}
