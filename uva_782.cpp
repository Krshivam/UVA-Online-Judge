#include<bits/stdc++.h>
using namespace std;
bool visited[35][84];
char grid[35][84];

int n=0,m=0;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void dfs(int x,int y){
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && grid[dx1][dy1]!='\0' && !visited[dx1][dy1]){
			if(grid[dx1][dy1]=='X'){
				grid[x][y] = '#';
			}
			else dfs(dx1,dy1);
		}
	}
}
int x,y;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		n=0,m=0;
		char s[120];
		memset(visited,0,sizeof(visited));
		memset(grid,0,sizeof(grid));
		while(gets(grid[n])){
			if(grid[n][0]=='_') break;
			n++;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; grid[i][j]; ++j)
			{
				if(grid[i][j]=='*') x = i,y=j;
			}
			
		}
		dfs(x,y);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; grid[i][j]; ++j)
			{
				cout<<grid[i][j];
			}
			cout<<endl;
			
		}
	}
	return 0;
}