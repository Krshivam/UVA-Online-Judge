#include<bits/stdc++.h>
using namespace std;
int arr[100005];

int main(int argc, char const *argv[])
{
	int n;
	int kase = 1;
	while((cin>>n) && n!=-1){
		
		int i=0;
		arr[i] = n;
		i++;
		while((cin>>n) && n!=-1){
			arr[i] = n;
			i++;
		}
		int dp[i],dp1[i];
		for (int j = 0; j < i; ++j)
		{
			dp[j] = 1;
			dp1[j] = 1;
		}
		int mx=0;
		for (int j = 0; j <i ; ++j)
		{
			for(int k=0;k<j;k++){
				if(arr[k]>arr[j]){
					dp[j] = max(dp[j],1+dp[k]);
					mx = max(mx,dp[j]);
				}
				if(arr[k]<arr[j]){
					dp1[j] = max(dp1[j],1+dp1[k]);
					mx = max(mx,dp1[j]);
				}
			}
		}
		cout<<"Test #"<<kase<<":"<<endl;
		cout<<"	maximum possible interceptions: "<<mx<<endl;
		kase++;
	}
	return 0;
}