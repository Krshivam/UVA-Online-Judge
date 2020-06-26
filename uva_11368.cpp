#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

bool compare(pii a,pii b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int w,h;
		pii arr[n];
		int dp[n];
		for (int i = 0; i <n ; ++i)
		{
			cin>>w>>h;
			arr[i].first = w;
			arr[i].second = h;
			dp[i] = 1;
			//dp1[i] = 1;
		}
		sort(arr,arr+n,compare);
		int mx=1;
		for (int i = 0;i<n;i++)
		{
			for (int j = 0; j <i ; j++)
			{
				if(arr[i].second>arr[j].second){
					dp[i] = max(dp[i],1+dp[j]);
					mx = max(mx,dp[i]);
				}
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
