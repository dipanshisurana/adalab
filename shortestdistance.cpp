#include <iostream>
#include <queue> 
using namespace std; 
class QItem { 
public: 
	int row; 
	int col; 
	int dist; 
	QItem(int x, int y, int w) : row(x), col(y), dist(w) 
    {
	
}; 

int minDistance(char **grid,int N, int M) 
{ 
	QItem source(0, 0, 0);  
	bool **visited = new bool*[N];
	for(int i=0; i<M; i++)
		visited[i] = new bool[M]; 
		
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) 
		{ 
			if (grid[i][j] == '0') 
				visited[i][j] = true; 
			else
			if (grid[i][j] == 's') 
			{ 
			source.row = i; 
			source.col = j; 
			} 
		} 
	} 
	queue<QItem> q; 
	q.push(source); 
	visited[source.row][source.col] = true; 
	while (!q.empty()) { 
		QItem p = q.front(); 
		q.pop(); 
		if (grid[p.row][p.col] == 'd') 
			return p.dist;  
		if (p.row - 1 >= 0 && 
			visited[p.row - 1][p.col] == false) { 
			q.push(QItem(p.row - 1, p.col, p.dist + 1)); 
			visited[p.row - 1][p.col] = true; 
		}  
		if (p.row + 1 < N && 
			visited[p.row + 1][p.col] == false) { 
			q.push(QItem(p.row + 1, p.col, p.dist + 1)); 
			visited[p.row + 1][p.col] = true; 
		}  
		if (p.col - 1 >= 0 && 
			visited[p.row][p.col - 1] == false) { 
			q.push(QItem(p.row, p.col - 1, p.dist + 1)); 
			visited[p.row][p.col - 1] = true; 
		}  
		if (p.col + 1 < M && 
			visited[p.row][p.col + 1] == false) { 
			q.push(QItem(p.row, p.col + 1, p.dist + 1)); 
			visited[p.row][p.col + 1] = true; 
		} 
	} 
	return -1; 
} 
int main() 
{ 
	char **grid;
	int N, M;
	cout<<"Enter number of rows :";
	cin>>N;
	cout<<"Enter number of columns :";
	cin>>M;
	grid = new char*[N];
	for(int i=0; i<M; i++)
		grid[i] = new char[M];
	
	cout<<"Enter grid :\n";
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>grid[i][j];

	cout << "Min distance : "<<minDistance(grid,N,M)<<endl; 
	return 0; 
} 