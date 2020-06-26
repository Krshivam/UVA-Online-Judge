#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int parent[105];
std::vector<std::vector<int> > network;
int dfsRoot,rootChild;
std::vector<int> tin,tlow,vertices;
int n;
int timer=0;

void dfs(int u){
	//visited[u] = 1;
	tin[u] = tlow[u] = ++timer;
	for (int i = 0; i < network[u].size(); ++i)
	{
		if(!tin[network[u][i]]){
			parent[network[u][i]] = u;
			if(u==dfsRoot) rootChild++;

			dfs(network[u][i]);
			if(tlow[network[u][i]]>=tin[u]) vertices[u] = true;
			tlow[u] = min(tlow[u],tlow[network[u][i]]);
		}
		else if(network[u][i]!=parent[u]){
			tlow[u] = min(tlow[u],tin[network[u][i]]);
		}
	}
}


int main(){
	while((cin>>n)&&n){
		network.clear();
		network.resize(105);
		vertices.clear();
		vertices.resize(105,0);
		tin.clear();
		tin.resize(105,0);
		tlow.clear();
		tlow.resize(105,0);
		timer=0;
		string s;
		while(getline(cin,s) && s!="0"){
			stringstream ss(s);
			int u,v;
			ss>>u;
			while(ss>>v){
				network[u].pb(v);
				network[v].pb(u);
			}
		}
		
		for (int i = 1; i <=n; ++i)
		{
			if(!tin[i]){
				rootChild=0;
				dfsRoot = i;
				dfs(i);
				if(rootChild>1){
					vertices[i]=true;
				}
			}
		}
		cout<<count(vertices.begin(), vertices.end(),1)<<endl;
	}
}