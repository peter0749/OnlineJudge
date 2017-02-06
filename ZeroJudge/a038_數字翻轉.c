#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char[]);
char *pop(char*,int);

int main(void){
	char input[20];
	char *ptr=NULL;
	while(scanf("%s",&input)!=EOF){
		reverse(input);
	}
	return 0;
}

void reverse(char str[]){
	char *ptr1, *new_ptr;
	int strcount=strlen(str);
	int i=0,j;
	ptr1=str;
	new_ptr=(char*)malloc(sizeof(char)*(strcount+1));
	while(*(str+i)=='0'){
		i++;
	}
	if(i==strcount){
		printf("%d\n",0);
	}
	else{
		for(i=strcount-1,j=0;i>=0;i--,j++){
			*(new_ptr+j)=*(ptr1+i);
		}
		*(new_ptr+j)='\0';
		/*puts(new_ptr);*/
		puts(pop(new_ptr,strcount));
		}
}

char *pop(char* ptr2,int strcount){
	char *pop_ptr=ptr2;
	if(*(pop_ptr+strcount-1)=='0'){
		do{
			*(pop_ptr+strcount-1)='\0';
			strcount--;
		}while(*(pop_ptr+strcount-1)=='0');
	}
	if(*(pop_ptr)=='0'){
		do{
			pop_ptr++;
		}while(*(pop_ptr)=='0');
	}
	/*printf("%d\n",strcount);
	puts(pop_ptr);*/
	return pop_ptr;
}
