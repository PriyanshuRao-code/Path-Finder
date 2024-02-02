#include <stdio.h>
// 1 for reaching 'D' or 'd' from 'S' or 's'
// 0 for not reaching

int maze_block(int r,int c,char arr[][100],int i,int j){
	//Check for not going out of boundary
	if(i<0||i>r||j<0||j>c){
		return 0;
	}

	//Checking for either of 'D' or 'd'
	if(arr[i+1][j]=='D' || arr[i-1][j]=='D'|| arr[i][j+1]=='D' || arr[i][j-1]=='D'|| arr[i+1][j]=='d' || arr[i-1][j]=='d'|| arr[i][j+1]=='d' || arr[i][j-1]=='d'){
		return 1;
	}

	//Visited
	arr[i][j]='1';

	//Initializing
	int down=0;
	int up=0;
	int left=0;
	int right=0;

	//Checking in all four directions
	if(arr[i+1][j]=='0'){
		down= maze_block(r,c,arr,i+1,j);
	}
	if(arr[i-1][j]=='0'){
		up= maze_block(r,c,arr,i-1,j);
	}
	if(arr[i][j+1]=='0'){
		right= maze_block(r,c,arr,i,j+1);
	}
	if(arr[i][j-1]=='0'){
		left= maze_block(r,c,arr,i,j-1);
	}

	//Final Conditions
	if(up==1||down==1||right==1||left==1){
		return 1;
	}
	else{
		return 0;
	}

}
int main(){
	int r,c;
	printf("Enter the array size(rows and columns): ");
	scanf("%d %d",&r,&c);
	char arr[100][100];

	//Taking inputs
	printf("Enter the elements of array\n");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf(" %c",&arr[i][j]);
		}
	}

	//Checking for 'S' or 's'
	int a,b;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]=='S' || arr[i][j]=='s'){
				a=i;
				b=j;	
			}
		}
	}
	
	//Printing results
	int result = maze_block(r,c,arr,a,b);
	if(result==1){
		printf("Path from S to D is found.\n");
	}
	else{
		printf("Path from S to D does not exist.\n");
	}
	return 0;
}
