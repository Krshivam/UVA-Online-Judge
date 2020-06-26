#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
char grid[205][205];
int n;
bool visited[205][205],d;
int di[]= {-1,-1,0,0,1,1};
int dj[]= {-1,0,-1,1,0,1};

void dfs(int x,int y){
	visited[x][y] = true;
	for (int i = 0; i < 6; ++i)
	{
		int dx = x+di[i];
		int dy = y+dj[i];
		if(visited[dx][dy]==false && dx>=0 && dx<n && dy>=0 && dy<n && grid[dx][dy] == 'b'){
			if(dx==n-1){
				d=true;
				return ;
			}
			dfs(dx,dy);
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int kase = 1;
	while((cin>>n)&&n){
		//char grid[205][205];
		memset(visited,false,sizeof(visited));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>grid[i][j];
			}
		}
		d=false;
		for (int i = 0; i < n; ++i)
		{
			dfs(0,i);
			if(d) break;
		}
		if(d) cout<<kase<<" B"<<endl;
		else cout<<kase<<" W"<<endl;
		kase++;
	}
	return 0;
}