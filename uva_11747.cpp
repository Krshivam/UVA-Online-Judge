#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mp make_pair

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
		sort(g.begin(), g.end());
		std::vector<int> v1;

		std::vector<int> tree(n+1);
		for (int i = 0; i < n; ++i)
		{
			tree[i] = i;
		}
		for (int i = 0; i <g.size() ; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			if(tree[b]!=tree[c]){
				int new_id = tree[b];
				int old_id = tree[c];
				for (int j = 0; j < n; ++j)
				{
					if(tree[j]==old_id){
						tree[j] = new_id;
					}
				}
			}
			else v1.pb(a);
		}
		if(v1.size()==0){
			cout<<"forest"<<endl;
		}
		else{
			sort(v1.begin(), v1.end());
			for (int i = 0; i < v1.size(); ++i)
			{
				if(i==v1.size()-1) cout<<v1[i];
				else cout<<v1[i]<<" ";
			}
			cout<<endl;
		}
		
	}
	return 0;
}