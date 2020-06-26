#include<bits/stdc++.h>
using namespace std;

int n,m,q;
double dp[1<<13][13],sm=0.0;
double dist[51][51];
int arr[14];

double tsp(int mask,int pos){
	if(mask==(1<<q)-1){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1) return dp[mask][pos];
	double ans = 12334444.0;
	for (int i = 0; i < q; ++i)
	{
		if(mask&(1<<arr[i])==0){
			if(dist[pos][arr[i]]==0)
				ans = min(ans,tsp(mask|(1<<i),arr[i]));
			else ans = min(ans,dist[pos][arr[i]]+tsp(mask|(1<<i),arr[i]));
		}
	}
	return dp[mask][pos] = ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dist,0,sizeof(dist));
		memset(dp,-1,sizeof(dp));
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			double w;
			cin>>u>>v>>w;
			dist[u][v] = w;
			dist[v][u] = w;
		}
		//int q;
		cin>>q;
		arr[0] = 0;
		for (int i = 1; i<=q ; ++i)
		{
			cin>>arr[i];
			double w;
			cin>>w;
			sm+=w;
		}
		q++;
		double ans = tsp(1,0);
		cout<<ans<<" "<<sm<<endl;
	}
	return 0;
}