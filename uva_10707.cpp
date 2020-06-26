#include<bits/stdc++.h>
using namespace std;

int w,h,n;
int grid[105][105],grid1[105][105];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int ans=0;
void dfs(int x,int y){
	//visited[x][y] = 1;
	grid[x][y] = 0;
	ans++;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<w && dy1<h  && grid[dx1][dy1]==1){
			dfs(dx1,dy1);
	}
}
}
void dfs1(int x,int y){
	//visited[x][y] = 1;
	grid1[x][y] = 0;
	ans++;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<w && dy1<h  && grid1[dx1][dy1]==1){
			dfs1(dx1,dy1);
	}
}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		cin>>w>>h>>n;
		memset(grid,0,sizeof(grid));
		memset(grid1,0,sizeof(grid1));
		int x,y;
		for (int i = 0; i < n; ++i)
		{
			cin>>x>>y;
			grid[x][y] = 1;
		}
		
		for (int i = 0; i < n; ++i)
		{
			cin>>x>>y;
			grid1[x][y] = 1;
		}
		
		std::map<int, int> m;
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				cout<<grid[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				cout<<grid1[i][j];
			}
			cout<<endl;
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				ans=0;
				if(grid[i][j]==1){
					dfs(i,j);
					m[ans]++;
				}
			}
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				ans=0;
				if(grid1[i][j]==1){
					dfs1(i,j);
					m[ans]--;
				}
			}
		}

		
		std::map<int, int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			//cout<<it->first<<endl;
			if(it->second!=0) {cout<<"NO"<<endl;
			return 0;
		}
		}
		cout<<"YES"<<endl;
	}
	return 0;
}