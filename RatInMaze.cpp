#include<iostream>
using namespace std;
int n,m;
void Print(char Maze[][100]){
	for(int i=0;i<n;i++){
		for (int j = 0; j <m; j++){
			if(Maze[i][j]!='1')cout<<"0 ";
			else cout<<Maze[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;

}
void RatInMaze(char Maze[][100],int i,int j ){
	// Base Case:
	if(i==n-1&&j==m-1){
		Maze[i][j]='1';
		Print(Maze);
		return;
	}
	// Recursive CAse:
		/// Right Move

			if(Maze[i][j+1]!='X'&&j<m-1){
				Maze[i][j]='1';
				RatInMaze(Maze,i,j+1);
				Maze[i][j]='O';
			}
		// Down Move
			if(Maze[i+1][j]!='X'&&i<n-1){
				Maze[i][j]='1';
				RatInMaze(Maze,i+1,j);
				Maze[i][j]='O';
			}
}
int main(){
	
	cin>>n>>m;
	char Maze[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>Maze[i][j];
		}
	}
	RatInMaze(Maze,0,0);
	return 0;
}
/*
5 5
O X O X X
O O O O O
X O X O X
O O O O O
X O O X O 
*/