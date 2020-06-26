#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
priority_queue<pair<int,int> >pq;
std::vector<std::vector<pair<int,int> > > adjList;
int n,m;
std::vector<int> taken;

void process(int u){
	taken[u] = 1;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		if(!taken[adjList[u][i].first]){
			pq.push(mp(-adjList[u][i].second,-adjList[u][i].first));
		}
	}
}


int main(int argc, char const *argv[])
{
	while((cin>>n>>m)&&n){
		adjList.clear();
		taken.clear();
		taken.resize(n,0);
		adjList.resize(n);
		ll total=0;
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			total+=w;
			adjList[u].pb(mp(v,w));
			adjList[v].pb(mp(u,w));
		}
		process(0);
		ll cost=0;
		while(!pq.empty()){
			pair<int,int> node = pq.top();
			pq.pop();
			if(!taken[-node.second]){
				cost+= (-node.first);
				process(-node.second);
			}
		}
		cout<<total-cost<<endl;
	}
	return 0;
}