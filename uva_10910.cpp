#include<bits/stdc++.h>
using namespace std;
int dp[72][72];

int find_ways(int sm,int n,int t,int p){
	if(n==0){
		if(sm==t) return 1;
		return 0;
	}
	if(dp[sm][n]!=-1) return dp[sm][n];
	int ans=0;
	for (int i = p; i <=t; ++i)
	{
		if(sm+i<=t){
			ans += find_ways(sm+i,n-1,t,p);
		}
		
	}
	return dp[sm][n] = ans;
}


void bottom_up

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,t1,p;
		cin>>n>>t1>>p;
		memset(dp,-1,sizeof(dp));
		cout<<find_ways(0,n,t1,p)<<endl;
		//cout<<cnt<<endl;
	}
	return 0;
}