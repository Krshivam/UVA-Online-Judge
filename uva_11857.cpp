#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

std::vector<int> tree,rank;

void make_Set(int v){
	tree[v] = v;
	//rank[v] = 0;
}

int get_parent(int u){
	if(u==tree[u]) return u;
	return tree[u] = get_parent(tree[u]);
}

void unite(int a,int b){
	a = tree[a];
	b = tree[b];
	if(a!=b){
		tree[a] = b;
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	while((cin>>n>>m)&&n){
		std::vector<pair<int,pair<int,int> > > g;
		for (int i = 0; i < m; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			g.pb(mp(d,mp(u,v)));
		}
		tree.clear();
		//rank.clear();
		tree.resize(n);
		//rank.resize(n);
		for (int i = 0; i < n; ++i)
		{
			make_Set(i);
		}
		//cout<<"hello world";
		sort(g.begin(), g.end());
		int cnt=0;
		int x=-1;
		for (int i = 0; i < g.size(); ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			//cout<<"hello world";
			if(get_parent(b)!=get_parent(c)){
				cnt++;
				x=a;
				unite(b,c);
				
			}
		}
		
		if(x==-1 || cnt<n-1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<x<<endl;
	}
	return 0;
}