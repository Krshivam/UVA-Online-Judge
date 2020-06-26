#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
std::vector<std::vector<pair<int,int> > >adjList;
int dist[20005];

void dijkstra(int src){
	priority_queue<pair<int,int>,std::vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push(mp(0,src));
	dist[src] = 0;
	while(!pq.empty()){
		pair<int,int>f = pq.top();
		pq.pop();
		for (int i = 0; i < adjList[f.second].size(); ++i)
		{
			if(dist[adjList[f.second][i].first]>dist[f.second]+adjList[f.second][i].second){
				dist[adjList[f.second][i].first]=dist[f.second]+adjList[f.second][i].second;
				pq.push(mp(dist[adjList[f.second][i].first],adjList[f.second][i].first));
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		int n,m,s,t;

		adjList.clear();

		cin>>n>>m>>s>>t;
		adjList.resize(n+1);
		memset(dist,1000000,sizeof(dist));
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			adjList[u].pb(mp(v,w));
			adjList[v].pb(mp(u,w));
		}
		dijkstra(s);
		if(dist[t]>=1000000){
			cout<<"Case #"<<kase<<": unreachable"<<endl;
		}
		else cout<<"Case #"<<kase<<": "<<dist[t]<<endl;
		kase++;
	}
	return 0;
}