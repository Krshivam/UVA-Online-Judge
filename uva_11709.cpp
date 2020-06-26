#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,m;
int timer=0;
int component=0;

std::vector<std::vector<int> >graph;
std::vector<int> dfs_num,dfs_low,visited;
std::map<pair<string,string>, int> names;
stack<int>s;

void tarjans(int u){
	visited[u] = 1;
	dfs_num[u] = dfs_low[u] = ++timer;
	s.push(u);
	for (int i = 0; i < graph[u].size(); ++i)
	{
		if(dfs_num[graph[u][i]]==-1){
			tarjans(graph[u][i]);
		}
		if(visited[graph[u][i]]){
			dfs_low[u] = min(dfs_low[u],dfs_low[graph[u][i]]);
		}
	}
	if(dfs_low[u]==dfs_num[u]){
		component++;
		while(1){
			int src = s.top();
			s.pop();
			visited[src] = 0;
			if(src==u){
				break;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	while((cin>>n>>m)&&n){
		graph.clear();
		dfs_num.clear();
		dfs_low.clear();
		visited.clear();
		dfs_num.resize(n+1,-1);
		dfs_low.resize(n+1,0);
		visited.resize(n+1,0);
		graph.resize(n+1);
		names.clear();
		timer=0;
		component=0;
		for (int i = 0; i <n ; ++i)
		{
			string x,y;
			cin>>x>>y;
			names[mp(x,y)] = i+1;
		}
		for (int i = 0; i < m; ++i)
		{
			string x,y,w,z;
			cin>>x>>y>>w>>z;
			graph[names[mp(x,y)]].pb(names[mp(w,z)]);
		}
		for (int i = 1; i <=n; ++i)
		{
			if(dfs_num[i]==-1){
				tarjans(i);
			}
		}
		cout<<component<<endl;
	}
	return 0;
}