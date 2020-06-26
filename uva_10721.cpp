#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int n,k,m;
ll dp[60][60];


ll f(int x,int y){
	if(y==k){
		if(x==n) return 1;
		return 0;
	}
	//if(x>k) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	ll ans=0;
	for (int i = 1; i <=m ; ++i)
	{
		if(x+i<=n) ans+=f(x+i,y+1);
	}
	return dp[x][y]=ans;
}

int main(int argc, char const *argv[])
{
	while(cin>>n>>k>>m){
		memset(dp,-1,sizeof(dp));
		cout<<f(0,0)<<endl;
	}
	return 0;
}