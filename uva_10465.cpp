#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int c=0;

int find_burgers(int n,int m,int t){
	if(t==0){
		return 0;
	}
	if(t<0) return -222222222;
	//if(t<0) return -222222222;
	if(dp[t]!=-1) return dp[t];
	
	return dp[t] = max(1+find_burgers(n,m,t-n),1+find_burgers(n,m,t-m));
}

int main(int argc, char const *argv[])
{
	int n,m,t;
	while(cin>>n>>m>>t){
		memset(dp,-1,sizeof(dp));
		cout<<find_burgers(n,m,t)<<" "<<c<<endl;
	}
	return 0;
}