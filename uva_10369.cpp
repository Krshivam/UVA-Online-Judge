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
		int s,v;
		cin>>s>>v;
		std::vector<pair<int , pair<int,int> > > val;
		for (int i = 0; i < v; ++i)
		{
			int x,y;
			cin>>x>>y;
			val.pb(mp(i,mp(x,y)));
		}
		tree.clear();
		tree.resize(v,0);
		std::vector<pair<double,pair<int,int> > > g;
		for(int i=0;i<val.size();i++){
			for (int j=i+1;j<val.size();j++)
			{
				
					//cout<<it->second<<" "<<it1->second<<endl;
					double d = findDistance(val[i].second.first,val[i].second.second,val[j].second.first,val[j].second.second);
					g.pb(mp(d,mp(val[i].first,val[j].first)));
				
			}
		}
		for (int i = 0; i < v; ++i)
		{
			tree[i] = i;
		}
		//cout<<g.size();
		sort(g.begin(), g.end());
		int cnt=0;
		double ans=0;
		for (int i = 0; i < g.size(); ++i)
		{
			double a = g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;
			//cout<<a<<endl;
			if(cnt==v-s){
				break;
			}
			if(get_parent(b)!=get_parent(c)){
				cnt++;
				ans = a;
				unite(b,c);
			}
		}
		printf("%0.2f\n", ans);
	}
	return 0;
}