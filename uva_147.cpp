#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int arr[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
ll dp[6001][12];



ll make_change(int val,int j){
	if(val<0) return 0;
	if(val==0){
		return 1;
	}
	if(dp[val][j]!=-1) return dp[val][j];
	ll ans = 0;
	for (int i = j; i < 11; ++i)
	{
		ans+=make_change(val-arr[i],i);
	}
	return dp[val][j] = ans;
}

int main(int argc, char const *argv[])
{
	double val;
	cin>>val;
	while(val!=0){
		int n = (int) (val * 20);
		memset(dp,-1,sizeof(dp));
		printf("%6.2f%17llu\n", val, make_change(n,0));
		//cout<<make_change(n,0)<<endl;
		cin>>val;
	}
	return 0;
}