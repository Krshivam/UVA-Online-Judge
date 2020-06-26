#include<bits/stdc++.h>
using namespace std;
int dp[105][50005];
int arr[105];

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//int arr[n+1];
		int sm = 0;
		for (int i = 1; i < n+1; ++i)
		{
			cin>>arr[i];
			sm+=arr[i];
		}
		int x = sm/2;
		
		//memset(dp,0,sizeof(dp));
		for (int i = 0; i <=x; ++i)
		{
			dp[0][i]=0;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= x; ++j)
			{
				if(arr[i]>j){
					dp[i][j] = dp[i-1][j];
				}
				else dp[i][j] = max(dp[i-1][j],arr[i]+dp[i-1][j-arr[i]]);
			}
		}
		cout<<sm-dp[n][x]*2<<endl;
	}
	return 0;
}