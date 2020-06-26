#include<bits/stdc++.h>
using namespace std;
std::vector<int> tree;
#define pb push_back
#define mp make_pair

int get_parent(int a){
	if(tree[a]==a) return a;
	return tree[a] = get_parent(tree[a]);
}

void unite(int a,int b){
	a = get_parent(a);
	b = get_parent(b);
	if(a!=b) tree[b] = a;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<pair<int,pair<int,int> > > g;
		for (int i = 0; i < m; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			g.pb(mp(-d,mp(u,v)));
		}
		tree.clear();
		tree.resize(n,0);
		sort(g.begin(), g.end());
		for (int i = 0; i < n; ++i)
		{
			tree[i]= i;
		}
		int x=-1;
		for (int i = 0; i < m; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			if(get_parent(b)!=get_parent(c)){
				x = a;
				unite(b,c);
			}
		}
		cout<<"Case #"<<kase<<": "<<(-x)<<endl;
		kase++;
	}
	return 0;
}