#include<bits/stdc++.h>
using namespace std;

int m,length;
int dp[1<<20],len[20];

int f(int l,int bitmask){
	if(dp[bitmask]!=-1) return dp[bitmask];
	if(l>length/4) return 0;
	else if(l==length/4){
		if(bitmask==(1<<m)-1) return 1;
		l=0;
	}
	//cout<<dp[bitmask]<<endl;
	for (int i = 0; i < m; ++i)
	{
		if((bitmask&(1<<i))==0 && f(l+len[i],bitmask|(1<<i))){
			return 1;
		}
	}
	return dp[bitmask] = 0;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		//int m;
		cin>>m;
		memset(dp,-1,sizeof(dp));
		length=0;
		for (int i = 0; i < m; ++i)
		{
			cin>>len[i];
			length+=len[i];
		}
		if(length%4) cout<<"no"<<endl;
		else {
			cout<<(f(0,0)?"yes":"no")<<endl;
		}
	}
	return 0;
}