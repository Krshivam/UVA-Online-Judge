#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
std::vector<std::vector<int> > adjList;
int dist[1000][1000];
int r,c;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dijkstra(){
	dist[0][0] = adjList[0][0];
	priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
	q.push(mp(0,mp(0,0)));
	while(!q.empty()){
		pair<int,pair<int,int> > f = q.top();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x1 = f.second.first+dx[i];
			int y1 = f.second.second+dy[i];
			if(x1>=0 && y1>=0 && x1<r && y1<c && dist[x1][y1]>dist[f.second.first][f.second.second]+adjList[x1][y1]){
				dist[x1][y1]=dist[f.second.first][f.second.second]+adjList[x1][y1];
				q.push(mp(dist[x1][y1],mp(x1,y1)));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int  t;
	cin>>t;
	while(t--){
		adjList.clear();
		memset(dist,100,sizeof(dist));
		
		cin>>r>>c;
		adjList.resize(r,std::vector<int>(c));
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>adjList[i][j];
			}
		}
		dijkstra();
		cout<<dist[r-1][c-1]<<endl;
	}
	return 0;
}