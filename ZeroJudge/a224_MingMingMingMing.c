#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1001

int main(void)
{
	int odd_count;
	int yn;
	int i=0,j=0;
	char input[MAX];
	char pre_data[MAX];
	int end_index;
	while(scanf("%s",input)!=EOF)
	{
		int atz[26]={0};
		odd_count=0;
		yn=1;
		i=0;
		j=0;
		while(input[i]!='\0')
		{
			if('A'<=input[i] && input[i]<='Z')
			{
				pre_data[j]=tolower(input[i]);
				j++;
			}
			else if('a'<=input[i] && 'z'>=input[i])
			{
				pre_data[j]=input[i];
				j++;
			}
			i++;
		}
		pre_data[j]='\0';
		end_index=strlen(pre_data)-1;
		for(i=0;i<=end_index;i++)
		{
			atz[pre_data[i]-'a']+=1;
		}
		for(i=0;i<26;i++)
		{
			/*printf("%d\n",atz[i]);*/
			if(atz[i]%2==1)
				odd_count++;
		}
		if(odd_count<2)
			printf("yes !\n");
		else
			printf("no...\n");
		
	} 
	return 0;
}
