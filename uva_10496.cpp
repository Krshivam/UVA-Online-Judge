#include<bits/stdc++.h>
using namespace std;
#define mp make_pair;
#define pii pair<int,int>
#define inf 999999
int n;
int dp[1<<12][12];
int dist[15][15];

int tsp(int mask,int pos){
	if(mask==(1<<n)-1){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1) return dp[mask][pos];

	int ans=inf;

	for (int i = 0; i <n; ++i)
	{
		if((mask&(1<<i)) ==0){
			//cout<<ans<<endl;
			//cout<<mask<<endl;
			int ans1 = dist[pos][i]+tsp(mask|(1<<i) ,i);
			
			if(ans1<ans) ans = ans1;
		}
	}
	return dp[mask][pos] = ans;
}

int find_dist(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		int t1,t2;
		cin>>t1>>t2;
		int sx,sy;
		cin>>sx>>sy;
		//int coord;
		//cin>>coord;
		cin>>n;
		pii arr[n+1];
		arr[0].first = sx;
		arr[0].second = sy;
		for (int i = 1; i <=n; ++i)
		{
			int x,y;
			cin>>x>>y;
			arr[i].first = x;
			arr[i].second = y;
		}
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <=n; ++j)
			{
				if(i!=j){
					dist[i][j] = find_dist(arr[i].first,arr[i].second,arr[j].first,arr[j].second);
					//cout<<dist[i][j]<<endl;
				}
			}
		}
		// /cout<<"hello";
		//coord+1;
		n++;
		cout<<"The shortest path has length "<<tsp(1,0)<<endl;
	}
	return 0;
}