#include <stdio.h>
#include <stdlib.h>

int list_output(char);
int real_or_fake(void);
char input[11]={0};

int main(void){
	while(scanf("%s",&input)!=EOF){
		if(real_or_fake()==1)	printf("real\n");
		else	printf("fake\n");
	}
	return 0;
}

int list_output(char c){
	switch(c){
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		case 'G': return 16;
		case 'H': return 17;
		case 'I': return 34;
		case 'J': return 18;
		case 'K': return 19;
		case 'L': return 20;
		case 'M': return 21;
		case 'N': return 22;
		case 'O': return 35;
		case 'P': return 23;
		case 'Q': return 24;
		case 'R': return 25;
		case 'S': return 26;
		case 'T': return 27;
		case 'U': return 28;
		case 'V': return 29;
		case 'W': return 32;
		case 'X': return 30;
		case 'Y': return 31;
		case 'Z': return 33;
		default : return 0;
	}
}

int real_or_fake(void){
	int sum,temp=0,i,j;
	for(i=1,j=8;i<=8;i++,j--){
		temp+=(input[i]-'0')*j;
	}
	temp+=(input[9]-'0');
	sum=list_output(input[0])/10 + (list_output(input[0])%10)*9 + temp;
	if(sum%10==0)	return 1;
	else return 0;
}
