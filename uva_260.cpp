#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
char grid[205][205];
int n;
int visited[205][205];
int di[]= {-1,-1,0,0,1,1};
int dj[]= {-1,0,-1,1,0,1};

bool isValid(int x,int y){
	if((x>=0 && x<n && y>=0 && y<n) && grid[x][y] == 'b') return true;
	return false;
}

void bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push(mp(x,y));
	visited[x][y] = 1;
	while(!q.empty()){
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();
		//if(dx==n-1 && grid[dx][dy]=='b') return true;
		for (int i = 0; i < 6; ++i)
		{
			if(isValid(dx+di[i],dy+dj[i]) && !visited[x][y]){
				q.push(mp(dx+di[i],dy+dj[i]));
				visited[x][y] = 1;
			}
		}
	}
	//return false;
}

int main(int argc, char const *argv[])
{
	
	int kase = 1;
	while((cin>>n)&&n){
		memset(visited,0,sizeof(visited));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>grid[i][j];
			}
		}
		bool flg= 0;
		for (int i = 0; i < n; ++i)
		{
				if(grid[0][i]=='b'){
					bfs(0,i);
				}
		}
		for(int i=0;i<n;i++){
			if(visited[n-1][0]==1){
				flg=1;
				break;
			}
		}
		if(flg) cout<<"B";
		else cout<<"W";
	}
	return 0;
}