#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	int n;
	int kase=1;
	while(cin>>n){
		int arr[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>arr[i];
		}
		int m;
		cin>>m;
		std::vector<pair<int,int> > adjlist;
		int dist[n+1];
		for (int i = 1; i <=n; ++i)
		{
			dist[i] = 1000000;
		}
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			cin>>u>>v;
			adjlist.pb(mp(u,v));
		}
		dist[1] = 0;
		int x=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(dist[adjlist[j].second]>dist[adjlist[j].first]+arr[adjlist[j].second]-arr[adjlist[j].first]){
					if(i==n-1) x=1;
					dist[adjlist[j].second]=dist[adjlist[j].first]+arr[adjlist[j].second]-arr[adjlist[j].first];
				}
			}
		}
		cout<<"Set #"<<kase<<endl;
		int q;
		cin>>q;
		while(q--){
			int u;
			cin>>u;
			if(dist[u]<3 || x) cout<<'?'<<endl;
			else cout<<dist[u]<<endl;
		}
		kase++;
	}
	return 0;
}