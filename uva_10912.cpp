#include<bits/stdc++.h>
using namespace std;

int dp[1001][27][31];

int f(int l,int s,int idx){
	if(l==0){
		if(s==0) return 1;
		return 0;
	}
	if(dp[s][idx][l]!=-1) return dp[s][idx][l];
	int ans=0;
	for(int j=idx;j<=26;j++){
		if(s-j>=0){
			ans += f(l-1,s-j,j+1);
		}
	}
	return dp[s][idx][l]=ans;
}

int main(int argc, char const *argv[])
{
	int l,s;
	int idx=1;
	while((cin>>l>>s)&&l){
		if(l>30||s>900) cout << "Case " << idx << ": 0"<< endl ;
		else{
			memset(dp,-1,sizeof(dp));
			cout<<"Case "<<idx<<": "<<f(l,s,1)<<endl;
			
		}
		idx++;
	}
	return 0;
}