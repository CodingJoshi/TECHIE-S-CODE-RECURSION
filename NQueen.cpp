#include<iostream>
using namespace std;
void Print(char board[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]=='Q')cout<<board[i][j]<<" ";
			else cout<<"_ ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isSafe(int row,int col,char board[][100],int n){
	// col check
	for(int x=row;x>=0;x--){
		if(board[x][col]=='Q')return false;
	}
	// right diagnol
	int i=row,j=col;
	while(i>=0&&j<n){
		if(board[i][j]=='Q')return false;

		i--;j++;
	}
	i=row;j=col;
	// left diagonal
	while(i>=0&&j>=0){	
		if(board[i][j]=='Q')return false;
		i--;j--;
	}	
return true;
}
bool NQueen(int row,char board[][100],int n){
	//Base Case:
		if(row==n){
			Print(board,n);
			return true;
		}
	// Recursive CASE:
		for(int j=0;j<n;j++){
			if(isSafe(row,j,board,n)){
				board[row][j]='Q';
				int ans=NQueen(row+1,board,n);
				if(ans==true)return true;
				board[row][j]=' ';
			}
		}
return false;
}
int main(){
		int n;
		cin>>n;
		char board[100][100];
		int ans=NQueen(0,board,n);
		if(ans==false)cout<<" It is not possible to place Queen";
	return 0;
}