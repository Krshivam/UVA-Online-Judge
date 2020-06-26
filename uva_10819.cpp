#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int dp[10001][101];
pii wt[101];

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>m>>n){
		int cnt=0;
		for (int i = 0; i < n; ++i)
		{
			int w,item;
			cin>>w>>item;
			wt[i].first = w;
			wt[i].second = item;
			cnt+=w;
		}
		if(m>1800) m+=200;
		for (int i = 0; i <=m; ++i)
		{
			dp[i][0] = 0;
		}
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 0; j <=m; ++j)
			{
				if(wt[i].first>j) dp[j][i] = dp[j][i-1];
				else dp[j][i] = max(dp[j][i-1],wt[i].second+dp[j-wt[i].first][i]);
			}
		}
		//m-=200;
		int r=0;
		for (int i = 1; i <=m; ++i)
		{
			cout<<dp[i][n]<<endl;
		}
	}
	return 0;
}