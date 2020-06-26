#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
std::vector<int> tree,visited;
std::vector<std::vector<pair<int,int> > > adjList;


int get_parent(int a){
	if(tree[a]==a) return a;
	return tree[a] = get_parent(tree[a]);
}

void unite(int a,int b){
	a= get_parent(a);
	b = get_parent(b);
	if(a!=b) tree[b] = a;
}

int ans1;

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
	cin>>n>>m>>k;
	int kase = 1;
	while(1){
		tree.clear();
		adjList.clear();
		tree.resize(n+1,0);
		adjList.resize(n+1);
		std::vector<pair<int,pair<int,int> > > g;
		for (int i = 0; i < m; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			g.pb(mp(d,mp(u,v)));
		}
		sort(g.begin(), g.end());
		for (int i = 0; i <=n; ++i)
		{
			tree[i] = i;
		}
		for (int i = 0; i < m; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			if(get_parent(b)!=get_parent(c)){
				adjList[b].pb(mp(c,a));
				adjList[c].pb(mp(b,a));
				unite(b,c);
			}
		}
		cout<<"Case #"<<kase<<endl;
		while(k--){
			int u,v;
			cin>>u>>v;
			ans1=-1;
			visited.clear();
			visited.resize(n+1,0);
			dfs(u,v,-1);
			if(ans1==-1) cout<<"no path"<<endl;
			else cout<<ans1<<endl;
		}
		kase++;
		if((cin>>n>>m>>k)&&n) cout<<endl;
		else break;
	}
	return 0;
}