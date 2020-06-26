#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		cout<<setw(2);
		int n = s1.length();
		int m = s2.length();
		if(n==0 || m==0){
			cout<<0<<endl;
		}
		else{
			int dp[n+1][m+1];
		for (int i = 0; i <=n ; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if(i==0||j==0) dp[i][j]=0;
				else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[n][m]<<endl;
		}
		
	}
	return 0;
}