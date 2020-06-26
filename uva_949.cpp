#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
int dx[] = {0,0,-1,1};
int dy[]= {1,-1,0,0};

int grid[101][101];
int visited[101][101],dist[101][101];
set<pair<pair<int,int>,int> >track;
int n,m;
set<pair<pair<int,int>,pair<int,int> > >s;

void bfs(){
	queue<pii>q;
	q.push(mp(0,0));
	visited[0][0] = 1;
	dist[0][0] = 0;
	while(!q.empty()){
		pii x = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x1 = dx[i]+x.first;
			int y1 = dy[i]+x.second;
			if(x1>=0 && y1>=0 && x1<n && y1<m && !visited[x1][y1] && s.find(mp(mp(x.first,x.second),mp(x1,y1)))==s.end()){
				dist[x1][y1] = 1+dist[x.first][x.second];
				while(track.find(mp(mp(x1,y1),dist[x1][y1]))!=track.end()){
					dist[x1][y1]+=1;
				}
				visited[x1][y1] = 1;
				q.push(mp(x1,y1));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	while(cin>>n>>m){
		memset(grid,0,sizeof(grid));
		memset(visited,0,sizeof(visited));
		track.clear();
		s.clear();
		memset(dist,0,sizeof(dist));
		int t;
		cin>>t;
		for (int i = 0; i < t; ++i)
		{
			int x,y,x1,y1;
			cin>>x>>y>>x1>>y1;
			s.insert(mp(mp(x,y),mp(x1,y1)));
		}
		int c;
		cin>>c;
		for (int i = 0; i < c; ++i)
		{
			int t1,x,y;
			cin>>t1>>x>>y;
			track.insert(mp(mp(x,y),t1));
			
		}
		//grid[n-1][m-1] = 0;
		bfs();
		cout<<dist[n-1][m-1]<<endl;
	}
	return 0;
}