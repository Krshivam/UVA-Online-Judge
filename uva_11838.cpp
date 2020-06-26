#include <bits/stdc++.h>
using namespace std;
#define pb push_back
std::vector<std::vector<int> >graph;
std::vector<int> dfs_num,dfs_low,visited;

stack<int>s;
int component=0;
int n,m;
int timer=0;
void tarjan(int u){
	
	visited[u] = 1;
	dfs_num[u] = dfs_low[u] = ++timer;
	s.push(u);
	for (int i = 0; i < graph[u].size(); ++i)
	{
		if(dfs_num[graph[u][i]]==-1){
			tarjan(graph[u][i]);
			//dfs_low[u] = min(dfs_low[u],dfs_low[graph[u][i]]);
		}
		if(visited[graph[u][i]]){
			dfs_low[u] = min(dfs_low[u],dfs_low[graph[u][i]]);
		}
	}

	//cout<<u<<endl;
	if(dfs_low[u]==dfs_num[u]){
		component++;
		//cout<<component<<endl;
		while(1){
			int cr = s.top();
			visited[cr] = 0;
			s.pop();
			if(cr==u){
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	while((cin>>n>>m)&&n){
		int u,v,p;
		graph.clear();
		dfs_num.clear();
		dfs_low.clear();
		visited.clear();
		dfs_num.resize(n+1,-1);
		dfs_low.resize(n+1,0);
		visited.resize(n+1,0);
		graph.resize(n+1);
		timer++;
		component=0;
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v>>p;
			graph[u].pb(v);
			if(p==2){
				graph[v].pb(u);
			}
		}
		for (int i = 1; i <=n; ++i)
		{
			if(dfs_num[i]==-1){
				//component++;
				tarjan(i);
			}
		}
		if(component>1) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}