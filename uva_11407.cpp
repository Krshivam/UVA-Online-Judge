#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int find_sum(int n){
	if(n==0){
		return 0;
	}
	int ans=999999;
	if(dp[n]!=-1) return dp[n];
	for (int i = 1; i <=n; ++i)
	{
		if(n-i*i>=0){
			ans = min(ans,1+find_sum(n-i*i));
		}
	}
	return dp[n] = ans;
}

void bottom_up_dp(){
	dp[1] = 1;
	dp[0]=0;
	for (int i = 1; i <=10000; ++i)
	{
		for (int j = 1; j*j <=i; j++)
		{
			if(i-j*j>=0){
				dp[i] = min(dp[i],1+dp[i-j*j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	memset(dp,9999,sizeof(dp));
	//find_sum(10000);
	bottom_up_dp();
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}