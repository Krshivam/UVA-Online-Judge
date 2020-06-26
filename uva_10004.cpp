#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<int> visited;
std::vector<int> clr;
#define pb push_back

bool isBipartite(int node,int color){
	visited[node] = 1;
	clr[node] = color;
	for (int i = 0; i < adjlist[node].size(); ++i)
	{
		if(!visited[adjlist[node][i]]){
			return isBipartite(adjlist[node][i],1-color);
		}
		else if(clr[adjlist[node][i]]==color){
			return false;
		}
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		int m;
		cin>>m;
		adjlist.clear();
		visited.clear();
		clr.clear();
		adjlist.resize(n);
		visited.resize(n,0);
		clr.resize(n,-1);
		int u,v;
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v;
			adjlist[u].pb(v);
			adjlist[v].pb(u);
		}
		if(isBipartite(0,1)){
			cout<<"BICOLORABLE."<<endl;
		}
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	return 0;
}