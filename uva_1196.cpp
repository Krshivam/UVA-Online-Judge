#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		pii arr[n];
		int dp[n];
		for (int i = 0; i < n; ++i)
		{
			int w,h;
			cin>>w>>h;
			arr[i].first = w;
			arr[i].second = h;
			dp[i] = 1;
		}
		sort(arr,arr+n);
		int mx = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(arr[i].second>arr[j].second){
					dp[i] = max(dp[i],dp[j]+1);
					mx = max(mx,dp[i]);
				}
			}
		}
		cout<<mx<<endl;
	}
	cout<<'*';
	return 0;
}