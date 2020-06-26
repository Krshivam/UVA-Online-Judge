#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000
int dp[101][101];

int find_ways(int x,int n,int k){
	if(k==0){
		if(n==x) return 1;
		return 0;
	}
	if(dp[x][k]!=-1) return dp[x][k];
	int ans=0;
	for (int i = 0; i <=n; ++i)
	{
		if(x+i<=n){
			ans += (find_ways(x+i,n,k-1))%MOD;
		}
	}
	return dp[x][k]=ans%MOD;
}

/*void bottom_up_dp(int n,int k){

	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			for (int i = k; i >=0; i--)
			{
				
			}
		}
	}
}
*/

int main(int argc, char const *argv[])
{
	int n,k;
	while((cin>>n>>k) && n){
		memset(dp,-1,sizeof(dp));
		cout<<find_ways(0,n,k)<<endl;
	}
	return 0;
}