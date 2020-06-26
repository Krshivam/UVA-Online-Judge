#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
std::vector<int> tree;

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
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<pair<int,pair<int,int> > >  g;
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			g.pb(mp(w,mp(u,v)));	
		}
		sort(g.begin(),g.end());
		tree.clear();
		tree.resize(n+1,0);
		for (int i = 1; i <=n ; ++i)
		{
			tree[i] = i;
		}
		int cost=0;
		std::vector<int> mst;
		for (int i = 0; i < m; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c= g[i].second.second;
			if(get_parent(b)!=get_parent(c)) {
				mst.pb(i);
				cost+=a;
				unite(b,c);
			}
		}

		cout<<cost<<" ";
		ll mx = 1e9;
		for (int i = 0; i <mst.size() ; ++i)
		{
			ll x = 0;
			int idx = mst[i];
			int cnt=0;
			for (int j = 1; j <=n ; ++j)
			{
				tree[j] = j;
			}
			for (int j = 0; j < m; ++j)
			{
				if(idx!=j){
					int a = g[j].first;
					int b = g[j].second.first;
					int c= g[j].second.second;
					if(get_parent(b)!=get_parent(c)) {
						//mst.pb();
						x+=a;
						unite(b,c);
						cnt++;
					}
				}
			}
			//cout<<x<<endl;
			if(cnt==n-1 && mx>x) mx = x;
		}
		cout<<mx<<endl;
	}
	return 0;
}