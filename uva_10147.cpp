#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define mp make_pair
std::vector<int> tree;


double findDistance(int x1,int y1,int x2,int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

int get_parent(int a){
	if(tree[a]==a) return a;
	return tree[a] = get_parent(tree[a]);
}

void unite(int a,int b){
	a = get_parent(a);
	b = get_parent(b);
	if(a!=b) tree[b]=a;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<pair<int , pair<int,int> > > val;
		//int cn = 1;
		for (int i = 0; i < n; ++i)
		{
			int x,y;
			cin>>x>>y;
			val.pb(mp(i+1,mp(x,y)));
			//cn++;
		}
		int m;
		cin>>m;
		//std::map<pair<int,int>, int> connented;
		tree.clear();
		tree.resize(n+1,0);
		for (int i = 0; i <=n; ++i)
		{
			tree[i] = i;
		}
		int cnt=0;
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin>>x>>y;
			//connented[mp(x,y)] = 1;
			if(get_parent(x)!=get_parent(y)) unite(x,y),cnt++;
		}
		if(cnt==n-1){
			cout<<"No new highways need"<<endl;
		}
		else{

		
		std::vector<pair<double,pair<int,int> > > g;
		for(int i=0;i<val.size();i++){
			for (int j=i+1;j<val.size();j++)
			{
				//if(connented[mp(i+1,j+1)] || connented[mp(j+1,i+1)]) continue;
				double d = findDistance(val[i].second.first,val[i].second.second,val[j].second.first,val[j].second.second);
				g.pb(mp(d,mp(val[i].first,val[j].first)));
				
			}
		}
		
		sort(g.begin(), g.end());
		int cnt=0;
		std::vector<pair<int,int> > edges;
		for (int i = 0; i < g.size(); ++i)
		{
			double a = g[i].first;
			int b = g[i].second.first;
			int c= g[i].second.second;
			//if(cnt==n-m-1) break;
			if(get_parent(b)!=get_parent(c)){
				cnt++;
				if(b>c) edges.pb(mp(c,b));
				else edges.pb(mp(b,c));
				unite(b,c);
			}
		}
		
		
			for (int i = 0; i < edges.size(); ++i)
			{
				
				cout<<edges[i].first<<" "<<edges[i].second<<endl;
			}
		}
	}
	return 0;
}