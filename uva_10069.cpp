#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
ll dp[10005][105];

int f(int i,string s1,string s2,int idx){
	if(idx==s2.length()) return 1;
	if(idx>s2.length() || i>=s1.length()) return 0;
	if(dp[i][idx]!=-1) return dp[i][idx];
	int ans = 0;
	
		if(s1[i]==s2[idx]){
			ans += f(i+1,s1,s2,idx+1)+f(i+1,s1,s2,idx);
		}
		else ans+=f(i+1,s1,s2,idx);
	
	return dp[i][idx]=ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		cout<<f(0,s1,s2,0)<<endl;
	}
	return 0;
}