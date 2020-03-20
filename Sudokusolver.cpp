#include<iostream>
using namespace std;
void Print(int board[][9]){
	for(int i=0;i<9;i++){
		if(i%3==0)cout<<"----------------------------"<<endl;
		for(int j=0;j<9;j++){
			if(j%3==0)cout<<" | ";
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"----------------------------"<<endl;
}
void nextUnassingnedCell(int board[][9],int& i,int& j){

	while(board[i][j]!=0){
		if(j==8){
			i++;j=0;
		}
		else j++;
	}
}

bool confilict(int board[][9],int i,int j,int no){

	/// Row check1
	for(int x=0;x<9;x++)if(board[i][x]==no)return true;
	// Col check
	for(int x=0;x<9;x++)if(board[x][j]==no)return true;
	// Grid CHeck
	int grs=(i/3)*3;
	int gcs=(j/3)*3;
	for(int x=grs;x<grs+3;x++){
		for(int y=gcs;y<gcs+3;y++){
			if(board[x][y]==no)return true;
		}
	}
	return false;
}


bool SudokuSolver(int board[][9],int i,int j){
	//base case:
	if(i==9&&j==0){
		Print(board);
		return true;
	}
	// recursive CAse:
		// find next unassinged Cell
		if(board[i][j]!=0) nextUnassingnedCell(board,i,j);
		/// filling the nos
		for(int no=1;no<=9;no++){
			if(confilict(board,i,j,no)==false){
				board[i][j]=no;
				int ans=false;
				if(j==8){
					ans=SudokuSolver(board,i+1,0);
				}
				else{
					ans=SudokuSolver(board,i,j+1);
				}
				if(ans==true)return ans;
				board[i][j]=0;
			}
		}
return false;
}
int main(){
	int board[9][9]={ 	
						{3,0,6,5,0,8,4,0,0},
						{5,2,0,0,0,0,0,0,0},
						{0,8,7,0,0,0,0,3,1},
						{0,0,3,0,1,0,0,8,0},
						{9,0,0,8,6,3,0,0,5},
						{0,5,0,0,9,0,6,0,0},
						{1,3,0,0,0,0,2,5,0},
						{0,0,0,0,0,0,0,7,4},
						{0,0,5,2,0,6,3,0,0},
					};
	Print(board);
	SudokuSolver(board,0,0);
	return 0;
}