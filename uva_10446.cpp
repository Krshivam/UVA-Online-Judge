#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll dp[62];


ll trib(int n,  int back)
{
	//if(n<=0) return 0;
	if(n<=1) return 1;
	if(dp[n]!=-1) return dp[n];
	ll sm=1;
	for(int i=1;i<=back;i++)
		sm+=trib(n-i,back);
	return dp[n]=sm;
}

int main(int argc, char const *argv[])
{
	int n,b;
	int kase=1;
	while(cin>>n>>b){
		//countt=0;
		memset(dp,-1,sizeof(dp));	
		//trib(n,b);
		if(n>60) break;
		cout<<"Case "<<kase<<": "<<trib(n,b)<<endl;
		kase++;
	}
	return 0;
}