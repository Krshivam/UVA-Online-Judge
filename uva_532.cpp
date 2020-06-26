#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
char grid[31][31][31];
int visited[31][31][31],dist[31][31][31];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};

int n,m,l;

void bfs(int x,int y,int z,int x_1,int y_1,int z_1){
	visited[x][y][z]  =1;
	dist[x][y][z]  =0;
	queue<pair<int,pair<int,int> > >q;
	q.push(mp(x,mp(y,z)));
	//int v=0;
	while(!q.empty()){
		pair<int,pair<int,int> >f= q.front();
		q.pop();
		if(f.first==x_1 && f.second.first==y_1 && f.second.second==z_1){
				cout<<"Escaped in "<<dist[x_1][y_1][z_1]<<" minute(s)."<<endl;
				return ;
		}
		for (int i = 0; i < 6; ++i)
		{
			int x1 = f.first+dx[i];
			int y1 = f.second.first+dy[i];
			int z1 = f.second.second+dz[i];
			
			if(x1>=0 && y1>=0 && z1>=0 && x1<n && y1<m && z1<l && !visited[x1][y1][z1] && grid[x1][y1][z1]=='.'){
				dist[x1][y1][z1] = 1+dist[f.first][f.second.first][f.second.second];
				//cout<<x1<<" "<<y1<<" "<<z1<<endl;
				//cout<<dist[x1][y1][z1] <<endl;
				q.push(mp(x1,mp(y1,z1)));
				visited[x1][y1][z1] = 1;
			}
		}
	}
	cout<<"Trapped!"<<endl;
}

int main(int argc, char const *argv[])
{
	
	while((cin>>n>>m>>l)&&n){
		int  x,y,z,x1,y1,z1;
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(visited));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <m ; ++j)
			{
				for (int k = 0; k < l; ++k)
				{
					cin>>grid[i][j][k];
					if(grid[i][j][k]=='S') x= i,y=j,z=k;
					else if(grid[i][j][k]=='E') x1=i,y1=j,z1=k,grid[i][j][k]='.';
				}
			}
		}
		//cout<<x<<" "<<y<<" "<<z;
		bfs(x,y,z,x1,y1,z1);
	}
	return 0;
}