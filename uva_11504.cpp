#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::vector<std::vector<int> > graph;
std::vector<int> dfs_num,dfs_low,visited;
int timer=0;
stack<int>s;
int component=0;
int n,m;

/*void scc(int u){
	visited[u] = 1;
	dfs_num[u] = dfs_low[u] =++timer;
	s.push(u);
	for (int i = 0; i < graph[u].size(); ++i)
	{
		if(visited[graph[u][i]]){
			dfs_low[u] = min(dfs_low[u],dfs_low[graph[u][i]]);
		}
		if(!visited[graph[u][i]]){
			scc(graph[u][i]);
		}
	}
	if(dfs_num[u]==dfs_low[u]){
		component++;
		while(1){
			if(s.top()==u){
				//visited[s.top()]=0;
				s.pop();
				break;
			}
			//visited[s.top()]=0;
			s.pop();
		}
	}
}
*/

void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < graph[u].size(); ++i)
	{
		if(!visited[graph[u][i]]){
			dfs(graph[u][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		graph.clear();
		dfs_num.clear();
		dfs_low.clear();
		visited.clear();
		dfs_num.resize(n+1,0);
		dfs_low.resize(n+1,0);
		visited.resize(n+1,0);
		graph.resize(n+1);
		
		std::vector<int> store;
		int x,y;
		timer=0;
		component=0;
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			graph[x].pb(y);
		}
		//graph[3].pb(1);
		for (int i = 1; i <= n; ++i)
		{
			if(!visited[i]){
				dfs(i);
				store.pb(i);
			}
			
		}
		visited.clear();
		visited.resize(n+1,0);
		int m=0;
		for (int i = store.size()-1; i>=0; i--)
		{
			if(!visited[store[i]]){
				dfs(store[i]);
				component++;
			}
		}
		cout<<component<<endl;
	}
	return 0;
}