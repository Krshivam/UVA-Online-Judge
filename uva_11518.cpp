#include<bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> > adjlist;
int visited[100005];
int n,m,l;
int ans=0;
int dfs(int v){
	visited[v] = 1;
	//ans++;
	for (int i = 0; i < adjlist[v].size(); ++i)
	{
		if(!visited[adjlist[v][i]]){
			
			dfs(adjlist[v][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		cin>>n>>m>>l;
		adjlist.clear();
		adjlist.resize(n+5);
		int u,v;
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v;
			adjlist[u].push_back(v);
			//adjlist[v].push_back(u);
		}
		//ans=0;
		for (int i = 0; i < l; ++i)
		{
			cin>>u;
			//ans = 0;
			dfs(u);
			//;
		}
		cout<<count(visited, visited+n+1,1)<<endl;
	}
	return 0;
}