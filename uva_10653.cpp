#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
char grid[1001][1001];
int visited[1001][1001];
int dist[1001][1001];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int r,c;



void bfs(int start_r,int start_c){
	queue<pair<int,int> >q;
	visited[start_r][start_c] = 1;
	q.push(mp(start_r,start_c));
	dist[start_r][start_c] = 0;
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i]+p.first;
			int y = dy[i]+p.second;
			if(x>=0 && x<r && y>=0 && y<c && grid[x][y]!='*' && !visited[x][y]){
					dist[x][y] = 1+dist[p.first][p.second];
				
					visited[x][y] = 1;
					q.push(mp(x,y));
				
				
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	while((cin>>r>>c)&&r){
		memset(grid,'.',sizeof(grid));
		memset(visited,0,sizeof(visited));
		memset(dist,9999999,sizeof(dist));
		//cout<<dist[1][2]<<endl;
		int loc;
		cin>>loc;
		while(loc--){
			int r1,t,c1;
			cin>>r1>>t;
			for (int i = 0; i < t; ++i)
			{
				cin>>c1;
				grid[r1][c1] = '*';
			}
		}
		int start_r,start_c,end_r,end_c;
		cin>>start_r>>start_c>>end_r>>end_c;
		bfs(start_r,start_c);
		cout<<dist[end_r][end_c]<<endl;
	}
	return 0;
}