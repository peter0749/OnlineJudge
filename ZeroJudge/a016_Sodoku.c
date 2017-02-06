#include <stdio.h>
#include <stdlib.h>

int input_sudoku(void);

int main(void){
	while(1){
		int state;
		state=input_sudoku();
		if(state==0)	break;
		else if(state==1)	printf("yes\n");
		else if(state==2)	printf("no\n"); 
	}
	return 0;
} 

int input_sudoku(void){
	int i,j;
	int sudoku[9][9];
	for(i=0;i<9;i++){
		if(scanf("%d %d %d %d %d %d %d %d %d",&sudoku[i][0],&sudoku[i][1],&sudoku[i][2],&sudoku[i][3],&sudoku[i][4],&sudoku[i][5],&sudoku[i][6],&sudoku[i][7],&sudoku[i][8])==EOF)	return 0;
		/*Return 0 if input==EOF, then break in main function.*/
	}
	/*for(i=0;i<9;i++){
		printf("Test\t");
		for(j=0;j<9;j++){
			printf("%d ",sudoku[i][j]);
		}
		printf("\n");
	}
	*/
	/*Compare x,y.*/
	int k,l,not_sudoku=0;
	for(i=0;i<9 && not_sudoku==0;i++){
		for(j=0;j<8 && not_sudoku==0;j++){
			for(k=j+1;k<9 && not_sudoku==0;k++){
				/*printf("in_Compare x,y.\n");*/
				if(sudoku[i][j]==sudoku[i][k]){
					/*printf("%d,%d\n%d,%d",i,j,i,k);*/
					not_sudoku=1;
					break;
				}
				if(sudoku[j][i]==sudoku[k][i]){
					/*printf("%d,%d\n%d,%d",j,i,k,i);*/
					not_sudoku=1;
					break;
				}
			}
		}
	}
	
	/*Compare 3x3.*/
	for(i=0;i<=6 && not_sudoku==0;i+=3){
		for(j=0;j<=6 && not_sudoku==0;j+=3){
			int temp[9]={0},m=0;
			for(k=i;k<=i+2 && not_sudoku==0;k++){
				for(l=j;l<=j+2 && not_sudoku==0;l++){
					/*printf("in_Compare 3x3, temp.\n");*/
					temp[m++]=sudoku[k][l];
					/*printf("temp=%d\n",temp[m]);*/
				}
			}
			for(k=0;k<8 && not_sudoku==0;k++){
				for(l=k+1;l<9 && not_sudoku==0;l++){
					/*printf("in_Compare x,y, sector 2.\n");*/
					if(temp[k]==temp[l]){
						/*printf("i=%d,j=%d%d,%d\n",i,j,k,l);*/
						not_sudoku=1;
						break;
					}
				}
			}
		}
	}
	/*not_sudoku=0;*/
	/*printf("not_sudoku=%d\n",not_sudoku);*/
	if(not_sudoku==1)	return 2;
	else	return 1;
}
