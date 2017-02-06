#include <stdio.h>
#include <math.h> 
void find_root(int, int, int);
int main(){
	int a,b,c; /*ax^2+bx+c=0*/
	while(scanf("%d %d %d",&a,&b,&c) != EOF){
	find_root(a,b,c);
	}
}
void find_root(int a,int b,int c){
	int x1=0,x2=0;
	float D=(b*b)-(4*a*c);
	if(D >= 0){
		x1=((-b)+sqrt(D))/(2*a);
		x2=((-b)-sqrt(D))/(2*a);
		if(x1==x2)	printf("Two same roots x=%d\n",x1);
		if(x1!=x2)	printf("Two different roots x1=%d , x2=%d\n",x1,x2);
	}
	else{
		printf("No real root\n");
	}
}
