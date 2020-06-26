#include<bits/stdc++.h>
using namespace std;

int k,n;

int main(int argc, char const *argv[])
{
	
	while(cin>>k>>n){
	double dp[n+1][k+1];
	for (int i = 0; i <=k; ++i)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <=n ; ++i)
	{
		for(int j=0;j<=k;j++){
			dp[i][j] = dp[i-1][j];
			if(j+1<=k) dp[i][j] += dp[i-1][j+1];
			if(j-1>=0) dp[i][j]+=dp[i-1][j-1];
		}
	}
	double sum=0.0;
	for (int i = 0; i <=k; ++i)
	{
		sum+=dp[n][i];
	}
	sum = sum*100.0/pow(k+1,n);
	printf("%0.5f\n", sum);
}
	return 0;
}