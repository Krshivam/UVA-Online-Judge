#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

char grid[105][105];
bool visited[101][101];
int dx[] = {1,0,0,-1,-1,-1,1,1};
int dy[] = {0,1,-1,0,-1,1,1,-1};
int ans = 1; //starting from waterland
int n=0,m;



void dfs(int x,int y){
	visited[x][y] = 1;
	for (int i = 0; i < 8; ++i)
	{
		int x1 = x+dx[i];
		int y1 = y+dy[i];
		if(!visited[x1][y1] && x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]=='W'){
			ans++;
			dfs(x1,y1);
		}
	}
	//visited[x][y] = 0;
	//cout<<ans<<endl;
	//return ans;
}


