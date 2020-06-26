#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
map<int,vector<int> > adjList;
map<int,int>dist,visited;
int x=0,y;

void bfs(int src){
	visited[src] = 1;
	dist[src] = 1;
	queue<int>q;
	q.push(src);
	std::map<int, int> m;
	
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < adjList[f].size(); ++i)
		{
			if(!visited[adjList[f][i]]){
				visited[adjList[f][i]] = 1;
				dist[adjList[f][i]] = dist[f]+1;
				m[dist[f]+1] += 1;
				//cout<<m[dist[f]+1]<<endl;
				if(m[dist[f]+1]>x){
					x = m[dist[f]+1];
					y = dist[f]+1;
				}
				q.push(adjList[f][i]);
			}
		}
	}
	if(x==0) cout<<x<<endl;
	else cout<<x<<" "<<y<<endl;
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	adjList.clear();
	//adjList.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int a,b;
		cin>>a;
		for (int j = 0; j < a; ++j)
		{
			cin>>b;
			adjList[i].pb(b);
			adjList[b].pb(i);
		}
	}
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		dist.clear();
		visited.clear();
		x = 0;
		bfs(a);
	}
	return 0;
}