#include<bits/stdc++.h>
using namespace std;

char grid[25][25];
bool visited[25][25];

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int n,m;
int sum=0;
void dfs(int x,int y,char c){
	visited[x][y] =1;
	sum++;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dy1<0) dy1 = m-1;
		if(dy1>=m) dy1 = 0;
		if(dx1>=0 && dx1<n && !visited[dx1][dy1] && grid[dx1][dy1]==c){
			dfs(dx1,dy1,c);
		}
	}
}

int main(int argc, char const *argv[])
{
	
	while((cin>>n>>m)){
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>grid[i][j];
			}
		}
		int x,y;
		cin>>x>>y;
			memset(visited,0,sizeof(visited));
			char c = grid[x][y];
			dfs(x,y,grid[x][y]);
			//int ans=1;
			int mx = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					sum = 0;
					if(!visited[i][j] && grid[i][j]==c){
						dfs(i,j,c);
						mx = max(sum,mx);
					}
				}
			}
			cout<<mx<<endl;
		
	}
	
	return 0;
}