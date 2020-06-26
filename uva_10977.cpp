#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
std::vector<pair<pair<int,int> ,int> > v;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int grid[201][201],dist[201][201],visited[201][201];
int r,c;

bool ispossible(int x,int y){
	int cnt=0;
	for (int i = 0; i < v.size(); ++i)
	{
		if(pow(x-v[i].first.first,2)+pow(y-v[i].first.second,2)<=pow(v[i].second,2)) cnt++;
	}
	return cnt>0?false:true;
}

void bfs(){
	dist[0][0]=0;
	visited[0][0]=1;
	queue<pii> q;
	q.push(mp(0,0));
	while(!q.empty()){
		pii f = q.front();
		q.pop();
		if(f.first==r-1 && f.second==c-1){
			cout<<dist[r-1][c-1]<<endl;
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			int x1 = f.first+dx[i];
			int y1 = f.second+dy[i];
			if(x1>=0 && y1>=0 && x1<r && y1<c && !visited[x1][y1] && grid[x1][y1]==1 && ispossible(x1,y1)){
				dist[x1][y1] = 1+dist[f.first][f.second];
				visited[x1][y1] = 1;
				//cout<<dist[x1][y1]<<endl;
				q.push(mp(x1,y1));
			}
		}
	}
	cout<<"Impossible."<<endl;
}

int main(int argc, char const *argv[])
{
	while((cin>>r>>c)&&r&&c){
		
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		v.clear();
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				grid[i][j]=1;
			}
			//cout<<endl;
		}
		int t;
		cin>>t;
		int x,y;
		for (int i = 0; i < t; ++i)
		{
			cin>>x>>y;
			x--,y--;
			grid[x][y] = 0;
		}
		cin>>t;
		
		for (int i = 0; i < t; ++i)
		{
			int d;
			cin>>x>>y>>d;
			x--,y--;
			v.pb(mp(mp(x,y),d));
		}
		bfs();
		
	}
	return 0;
}