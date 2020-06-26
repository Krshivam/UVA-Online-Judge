#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[25][25];


ll f(int i,int j,int n){
	if(dp[i][j]!=-1) return dp[i][j];
	if(i>=j){
		ll x = 0,y=0;
		for (int k = i+1; k <=n ; ++k)
		{
			x = max(x,f(k,1,n)+f(k,j,n));
		}
		for(int k=1;k<j;k++){
			y = max(y,f(i,k,n)+f(n,k,n));
		}
		return dp[i][j] = x+y;
	}
	else {
		ll x=0;
		for (int k = i; k <j ; ++k)
		{
			x = max(x,f(i,k,n)+f(k+1,j,n));
		}
		return dp[i][j] = x;
	}
	
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(cin>>a>>b){
		memset(dp,-1,sizeof(dp));
		dp[a][1] = b;
		cout<<f(1,a,a)<<endl;
	}
	return 0;
}