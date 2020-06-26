#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
std::vector<std::vector<pair<int,int> > >g;
priority_queue<pair<int,pair<int,int> > >pq;
std::vector<int> taken,visited;
std::vector<std::vector<pair<int,int> > > adjList;

int ans1;

void process(int u){
	taken[u] = 1;
	for (int i = 0; i <g[u].size() ; ++i)
	{
		if(!taken[g[u][i].first]){
			pq.push(mp(-g[u][i].second,mp(-g[u][i].first,-u)));
		}
	}
}

void dfs(int u,int v,int ans){
	//int ans = -1e9;
	visited[u] = true;
	if(u==v) ans1=ans;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		if(!visited[adjList[u][i].first]){
			dfs(adjList[u][i].first,v,max(ans,adjList[u][i].second));
		}
	}
	//ans = -1e9;
	//return ans;
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	int kase=1;
	cin>>n>>m>>k;
	while(1){
		g.clear();
		g.resize(n+1);
		adjList.clear();
		adjList.resize(n+1);
		taken.clear();
		taken.resize(n+1,0);
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
		}
		process(1);
		while(!pq.empty()){
			pair<int,pair<int,int> > node = pq.top();
			int d = -node.first;
			int v = -node.second.first;
			int p = -node.second.second;
			pq.pop();
			if(!taken[v]){
				process(v);
				adjList[p].pb(mp(v,d));
				adjList[v].pb(mp(p,d));
			}
		}
		/*for (int i = 0; i < adjList.size(); ++i)
		{
			for (int j = 0; j < adjList[i].size(); ++j)
			{
				cout<<i<<" "<<adjList[i][j].first<<" "<<adjList[i][j].second<<endl;
			}
		}*/
		//cout<<adjList.size();
		cout<<"Case #"<<kase<<endl;
		while(k--){
			int u,v;
			cin>>u>>v;
			visited.clear();
			visited.resize(n+1,0);
			//if(u>v) swap(u,v);
			ans1=-1;
			dfs(u,v,-1);
			if(ans1==-1){
				for (int i = 0; i < g[u].size(); ++i)
				{
					if(g[u][i].first==v) ans1=g[u][i].second;
				}
			}
			
			if(ans1==-1) cout<<"no path"<<endl;
			else cout<<ans1<<endl;
		}
		kase++;
		if((cin>>n>>m>>k)&&n) cout<<endl;
		else break;
	}
	return 0;
}