#include<bits/stdc++.h>
using namespace std;
#define ll long long
std::map<int, pair<string,ll> >h1,h2;
int n;
int m;
ll dp[1005][1005];
int cnt[1005][1005];

void f(int i,int j,ll cur,int cn){
	if(dp[i][j]<cur){
		dp[i][j] = cur;
		cnt[i][j] = cn;
	}
	else if(dp[i][j]==cur) cnt[i][j] = min(cnt[i][j],cn);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		h1.clear();
		h2.clear();
		//int n;
		cin>>n;
		string s1,s2;
		ll val;
		for (int i = 1; i <=n ; ++i)
		{
			cin>>s1>>s2>>val;
			h1[i].first = s2;
			h1[i].second = val;
		}
		//int m;
		cin>>m;
		for (int i = 1; i <= m; ++i)
		{
			cin>>s1>>s2>>val;
			h2[i].first = s2;
			h2[i].second = val;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j] = 0;
				cnt[i][j] = 0;
				ll cur = 0;
				int cn=0;
				if(h1[i].first==h2[j].first){
					cur = (i>1 && j>1?dp[i-1][j-1]:0)+h1[i].second+h2[j].second;
					cn = (i>1 && j>1?cnt[i-1][j-1]:0)+1;
				}
				if(i>1) f(i,j,dp[i-1][j],cnt[i-1][j]);
				if(j>1) f(i,j,dp[i][j-1],cnt[i][j-1]);
				f(i,j,cur,cn);
				
			}
			for(int i=1;i<=n;i++){
				for (int j = 1; j <=m ; ++j)
				{
					cout<<dp[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		cout<<dp[n][m]<<" "<<cnt[n][m]<<endl;
	}
	return 0;
}