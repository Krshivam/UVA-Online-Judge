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
	int kase=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		std::vector<pair<int,pair<int,int> > > g;
		for (int i = 0; i < m; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			g.pb(mp(d,mp(u,v)));
		}

		tree.clear();
		tree.resize(n+1,0);
		sort(g.begin(), g.end());
		for (int i = 1; i <=n; ++i)
		{
			tree[i] = i;
		}
		std::vector<int> mst;
		int cost=0;
		int cnt=0;
		for (int i = 0; i < m; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			if(get_parent(b)!=get_parent(c)){
				cost+=a;
				mst.pb(i);
				unite(b,c);
				cnt++;
			}
		}
		if(cnt!=n-1) {
			cout<<"Case #"<<kase<<" : No way"<<endl;
		}
		else{
			int mx = 1e9;
			int cont=0;
			int x=0;
			for (int i = 0; i < mst.size(); ++i)
			{
				cont=0;
				x=0;
				for (int j = 1; j <=n; ++j)
				{
					tree[j] = j;
				}
				for (int j = 0; j <m ; ++j)
				{
					if(mst[i]!=j){
						int a = g[j].first;
						int b = g[j].second.first;
						int c = g[j].second.second;
						if(get_parent(b)!=get_parent(c)){
							x+=a;
							unite(b,c);
							cont++;
						}
					}
				}
				if(cont==n-1 && mx>x) mx = x;
				//cout<<mx<<endl;
			}
			if(mx==1e9) cout<<"Case #"<<kase<<" : No second way"<<endl;
			else cout<<"Case #"<<kase<<" : "<<mx<<endl;
		}
		kase++;
	}
	return 0;
}