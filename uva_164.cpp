#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1,s2;
	while(cin>>s1 && s1!=""){
		cin>>s2;
		int n = s1.length();
		int m = s2.length();
		int dp[n+1][m+1];
		//memset(dp,0,sizeof(dp));
		for (int i = 0; i <= n; ++i)
		{
			dp[i][0] = i;
		}
		for (int i = 0; i <=m; ++i)
		{
			dp[0][i] = i;
		}
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <=m; ++j)
			{
				if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i][j-1],1+dp[i-1][j]));
			}
		}
		int i = n,j=m;
		while(i||j){
			if(s1[i-1]==s2[j-1]){
				i--,j--;
				continue;
			}
			if(j>0 && (dp[i][j]==dp[i][j-1]+1)){
				cout<<"I"<<s2[j-1];
				if(i<=9) cout<<0;
				cout<<i+1;
				j--;
			}
			else if(i>0 &&j>0 && (dp[i][j]==1+dp[i-1][j-1])){
				cout<<"C"<<s2[j-1];
				if(i<10) cout<<0;
				cout<<i;
				i--,j--;
			}
			else if(i>0){
				cout<<"D"<<s1[i-1];
				if(i<=9) cout<<0;
				cout<<i;
				i--;
			}
		}
		cout<<"E"<<endl;
	}
	return 0;
}