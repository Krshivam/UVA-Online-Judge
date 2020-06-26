#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,pair<int,int> > > adjlist;
		//adjlist.resize(n);
		int dist[n+1] ;
		//memset(dist,1000000,sizeof(dist));
		for (int i = 0; i < n; ++i)
		{
			dist[i]=1000000;
		}
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			adjlist.pb(mp(u,mp(v,w)));
			//adjlist.pb(mp(v,mp(u,w)));
		}
		int x=0;
		dist[0]=0;
		
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					if(dist[adjlist[k].second.first]>dist[adjlist[k].first]+adjlist[k].second.second){
						if(j==n-1) x=1;
						dist[adjlist[k].second.first]=dist[adjlist[k].first]+adjlist[k].second.second;
					}
				}
			}
		
		if(x) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	return 0;
}