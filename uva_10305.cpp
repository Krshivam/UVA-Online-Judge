#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m;
std::vector<int> adjlist[105];
bool visited[105];
stack<int>s;

void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i]]){
			dfs(adjlist[u][i]);
		}
	}
	s.push(u);
}

int main(int argc, char const *argv[])
{
	while((cin>>n>>m)&&n){
		int u,v;
		memset(visited,0,sizeof(visited));
		memset(adjlist,0,sizeof(adjlist));
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v;
			adjlist[u].pb(v);
		}
		for (int i = 1; i <=n ; ++i)
		{
			if(!visited[i]){
				dfs(i);
			}
		}
		while(s.size()){
			if(s.size()==1) cout<<s.top();
			else cout<<s.top()<<" ";
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}