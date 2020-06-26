#include<bits/stdc++.h>
using namespace std;
char grid[55][55];
int sum=0;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
void dfs_new(int x,int y){
	grid[x][y] = '*';
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && dy1<m && grid[dx1][dy1]=='X'){
			dfs_new(dx1,dy1);
		}
	}
}

void dfs(int x,int y){
	if(grid[x][y]=='X'){
		sum++;
		dfs_new(x,y);
	}
	grid[x][y] = '.';
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && dy1<m && grid[dx1][dy1]!='.'){
			dfs(dx1,dy1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int id=1;
	while((cin>>m>>n)&&n){
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>grid[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sum=0;
				if(grid[i][j]!='.'){
					dfs(i,j);
					v.push_back(sum);
				}
			}
		}
		sort(v.begin(), v.end());
		cout<<"Throw "<<id<<endl;
		for (int i = 0; i <v.size() ; ++i)
		{
			if(i==v.size()-1) cout<<v[i];
			else cout<<v[i]<<" ";
		}
		cout<<endl<<endl;
		id++;
	}
	return 0;
}