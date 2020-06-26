#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int kase=1;
	while(n--){
		string s1;
		cin>>s1;
		string s2(s1);
		reverse(s2.begin(), s2.end());
		int l = s1.length();
		memset(dp,0,sizeof(dp));
		//int dp[l+1][l+1];
		for (int i = 0; i <=l; ++i)
		{
			dp[i][0]=i;
		}
		for (int i = 0; i <=l; ++i)
		{
			dp[0][i]=i;
		}
		for (int i = 1; i <=l; ++i)
		{
			for (int j = 1; j <=l; ++j)
			{
				//if(i==0 || j==0) dp[i][j] = 0;
				if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
		}
		cout<<"Case "<<kase<<": "<<dp[l][l]/2<<endl;
		kase++;
	}
	return 0;
}