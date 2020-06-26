#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

std::vector<int> tree;

void make_set(int u){
	tree[u] = u;
}

int get_parent(int u){
	//cout<<"Hello";
	if(tree[u]==u) return u;
	return tree[u] = get_parent(tree[u]);
}

void unite(int a,int b){
	a = get_parent(a);
	b = get_parent(b);
	if(a!=b) {
		tree[b] = a;
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	while((cin>>n>>m)&&n){
		std::map<string, int> s_i;
		//std::map<int,string> i_s;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			s_i[s] = i;
			//i_s[i] = s;
		}
		std::vector<pair<int,pair<int,int> > > g;
		for (int i = 0; i < m; ++i)
		{
			string u,v;
			int d;
			cin>>u>>v>>d;
			//cout<<u<<" "<<v<<" "<<d<<endl;
			g.pb(mp(d,mp(s_i[u],s_i[v])));
		}
		string x;
		cin>>x;
		tree.clear();
		tree.resize(n+1);
		sort(g.begin(),g.end());
		int cnt=0;
		int cost=0;
		
		for (int i = 0; i < n; ++i)
		{
			make_set(i);
		}
		//
		for (int i = 0; i < m; ++i)
		{
			int a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			//cout<<a<<" "<<b<<" "<<c<<endl;
			if(get_parent(b)!=get_parent(c)){
				cnt++;
				cost+=a;
				unite(b,c);
			}
		}
		if(cnt<n-1) {
			cout<<"Impossible"<<endl;
		}
		else cout<<cost<<endl;

	}
	return 0;
}