#include <iostream>
using namespace std;
void printSolution(int **solution, int N){
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++)
			cout<<solution[i][j]<<"\t";
		cout<<endl;
	}//end of for
}//end of method
void ratMaze(int **maze, int **solution, int N, int x,int y){
	if(x==N-1 && y==N-1){
		solution[x][y] = 1;
		printSolution(solution,N);
		return;
	}//end of if
	if(x<0 || x>N-1 || y<0 || y>N-1 || maze[x][y]==0 || solution[x][y]==1) return;
	solution[x][y]=1;
	ratMaze(maze,solution,N,x,y+1); //right, i.e, forward
	ratMaze(maze,solution,N,x+1,y); //down
	solution[x][y]=0;
}//end of method
int main(){
	int N, **maze, **solution;
	cout<<"Enter size of matrix :";
	cin>>N;
	maze = new int*[N];
	for(int i =0; i<N; i++)
		maze[i] = new int[N];
	solution = new int*[N];
	for(int i =0; i<N; i++)
		solution[i] = new int[N];
	cout<<"Enter maze :\n";
	for(int i=0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>maze[i][j];
	ratMaze(maze,solution,N,0,0);
	return 0;
}