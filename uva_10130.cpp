#include<bits/stdc++.h>
using namespace std;

int dp[105];

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//int v[n+1],w[n+1];
		int v,w;
		
		int cnt=0;
		for (int i = 1; i <=31; ++i)
			{
				dp[i] = 0;
			}
		for (int i = 1; i <=n; ++i)
		{
			cin>>v>>w;
			for(int j=31;j>=w;j--){
				dp[j] = max(dp[j],v+dp[j-w]);
					//else dp[j][i] = dp[j];
			}
		}
		int q;
		cin>>q;
		while(q--){
			int wt;
			cin>>wt;
			//cout<<dp[wt]<<endl;
			cnt+=dp[wt];
		}
		cout<<cnt<<endl;
	}
	return 0;
}