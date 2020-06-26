#include<bits/stdc++.h>
using namespace std;
#define MAX 5000000
#define pb push_back
int n,m;
std::vector<std::vector<int> > adjlist;
int visited[MAX];
stack<int>s;
std::vector<int> strn;
int t;
void dfs(int u){
	visited[u] = 1;
	//parent[u] = x;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i]]){
			dfs(adjlist[u][i]);
		}
		else if(visited[adjlist[u][i]] == 1){
			t = 0;
			return;
		}
	}
	//cout<<u<<endl;
	strn.pb(u);
	visited[u] = 2;
	//visited[u] = 0;
	//cout<<u<<endl;
	//return true;
}

int main(int argc, char const *argv[])
{
	while((cin>>n>>m)&&n){
		adjlist.clear();
		strn.clear();
		//memset(parent,0,sizeof(parent));
		memset(visited,0,sizeof(visited));
		int u,v;
		adjlist.resize(MAX);
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v;
			adjlist[v].pb(u);
		}	
		t=1;

		for (int i = 1; i <= n; ++i)
		{
			if(!visited[i]){
				dfs(i);
			}
		}
		if(t){
			for (int i = 0; i < strn.size(); ++i)
			{
				cout<<strn[i]<<endl;
			}

		}
		else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}