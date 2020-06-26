#include<bits/stdc++.h>
using namespace std;
int n,r;
double arr[101];
double b,v,e,f;
double dp[105];

double time_(int j,int i){
	double sum=0;
	for(int k=0;k<arr[i]-arr[j];k++){
		if(k>=r) sum+=1.0/(v-e*(k-r));
		else sum+=1.0/(v-f*(r-k));
	}
	return (j)?sum+b:sum;
}

int main(int argc, char const *argv[])
{
	while((cin>>n)&&n){
		for (int i = 1; i <= n; ++i)
		{
			cin>>arr[i];
		}
		cin>>b>>r>>v>>e>>f;
		//cout<<f1(0.0,0);
		for(int i=1;i<=n;i++){
			dp[i] = 99999999999.0;
			for (int j = 0; j < i; ++j)
			{
				dp[i] = min(dp[i],dp[j]+time_(j,i));
			}
		}
		printf("%0.4f\n", dp[n]);
	}
	return 0;
}