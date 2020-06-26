#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		int ans=0;
		for (int i = 1; i <n ; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(arr[j]<=arr[i]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}