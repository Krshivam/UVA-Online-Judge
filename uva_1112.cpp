#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>


std::vector<std::vector<pii> >adjlist;
int dist[100005];
int n,e,t1;
void dijkstra(int src){
	priority_queue<pii,std::vector<pii> ,greater<pii> >pq;
	pq.push(mp(0,src));
	dist[src] = 0;
	int cnt=0;
	while(!pq.empty()){
		pii f = pq.top();
		pq.pop();
		for (int i = 0; i < adjlist[f.second].size(); ++i)
		{
			if(dist[adjlist[f.second][i].first]>dist[f.second]+adjlist[f.second][i].second){
				dist[adjlist[f.second][i].first]=dist[f.second]+adjlist[f.second][i].second;
				pq.push(mp(dist[adjlist[f.second][i].first],adjlist[f.second][i].first));
			}
		}
	}
	for (int i = 0; i < n+1; ++i)
	{
		if(dist[i]<=t1 && dist[i]<1000000) cnt++;
	}
	cout<<cnt<<endl;
}



int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		adjlist.clear();
		cin>>n>>e>>t1;
		adjlist.resize(n+1);
		for (int i = 0; i < n+1; ++i)
		{
			dist[i]=1000000;
		}
		int m;
		cin>>m;
		for (int i = 0; i <m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			adjlist[v].pb(mp(u,w));
		}
		dijkstra(e);
		if(t!=0) cout<<endl;
	}
	return 0;
}