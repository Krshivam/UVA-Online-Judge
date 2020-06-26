#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int dp[1001][1001];

int main(int argc, char const *argv[])
{
	int n,m;
	int kase=1;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0) break;
		cout<<"Twin Towers #"<<kase<<endl;
		std::vector<int> v1,v2;
		v1.resize(n);
		v2.resize(m);
		for (int i = 0; i < n; ++i)
		{
			cin>>v1[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>v2[i];
		}
		memset(dp,0,sizeof(dp));
		for (int i = 0; i <=n; ++i)
		{
			for (int j = 0; j <=m; ++j)
			{
				if(i==0||j==0) dp[i][j]=0;
				else if(v1[i-1]==v2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<"Number of Tiles : "<<dp[n][m]<<endl;
		cout<<endl;
		kase++;
	}
	return 0;
}