#include<bits/stdc++.h>
using namespace std;

const int infinite = 1e9+5;

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
		int mx = infinite;
		for (int i = 0; i < n; ++i)
		{
			int sm=0;
			for (int j = 0; j < n; ++j)
			{
				sm+=abs(arr[i]-arr[j]);
				
			}
			mx = min(mx,sm);
		}
		cout<<mx<<endl;
	}
	return 0;
}