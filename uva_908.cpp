#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
std::vector<int> tree;

int get_parent(int a){
	if(tree[a]==a) return a;
	return tree[a] = get_parent(tree[a]);
}

void unite(int a,int b){
	a = get_parent(a);
	b = get_parent(b);
	if(a!=b){
		tree[b] = a;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	//cin>>n;
	int cnt=0;
	while(cin>>n){
		std::vector<pair<int,pair<int,int> > > g,gk,gm;
		for (int i = 0; i < n-1; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			g.pb(mp(d,mp(u,v)));
		}
		for (int i = 0; i < n-1; ++i)
		{
			
			gk.pb(g[i]);
			gm.pb(g[i]);
		}
		int k;
		cin>>k;
		//cout<<k;
		for (int i = 0; i < k; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			gk.pb(mp(d,mp(u,v)));
		}
		//cout<<gm.size()<<" "<<gk.size()<<endl;
		int m;
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			gm.pb(mp(d,mp(u,v)));
		}
		
		sort(gm.begin(), gm.end());
		sort(gk.begin(), gk.end());
		tree.clear();
		tree.resize(n+1,0);
		for (int i = 0; i <=n; ++i)
		{
			tree[i] = i;
		}
		int cost=0;
		for (int i = 0; i < gm.size(); ++i)
		{
			int a = gm[i].first;
			int b = gm[i].second.first;
			int c = gm[i].second.second;
			if(get_parent(b)!=get_parent(c)){
				cost+=a;
				unite(b,c);
			}
		}
		if(cnt) cout<<endl;
		cout<<cost<<endl;
		//cost=0;
		tree.clear();
		tree.resize(n+1,0);
		for (int i = 0; i <=n; ++i)
		{
			tree[i] = i;
		}
		cost=0;
		for (int i = 0; i < gk.size(); ++i)
		{
			int a = gk[i].first;
			int b = gk[i].second.first;
			int c = gk[i].second.second;
			if(get_parent(b)!=get_parent(c)){
				cost+=a;
				unite(b,c);
			}
		}
		cout<<cost<<endl;
		cnt++;
	}
	return 0;
}