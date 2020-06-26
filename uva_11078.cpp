#include <bits/stdc++.h>
using namespace std;

const int mn = 1e9;
const int inf_neg = INT_MIN;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1],arr1[n+1],arr2[n+1];
		
		int ans=inf_neg;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		int mx=arr[0];
		int mni=arr[n-1];
		arr1[0] = mx;
		arr2[n-1] = mn;
		for (int i = 1; i < n-1; ++i)
		{
			mx = max(mx,arr[i]);
			arr1[i] = mx;
		}
		for (int i = n-2; i>0 ; i--)
		{
			mni = min(mni,arr[i]);
			arr2[i] = mni;
		}
		for (int i = 0; i < n-1; ++i)
		{
			ans = max(ans,arr1[i]-arr2[i+1]);
		}
		/*for (int i = 1; i < n; ++i)
		{
			ans = max(ans,max(mx-arr[i],mni-arr[i]));
			mx = max(arr[i],mx);
			mni = min(arr[i],mni);
		}*/
		cout<<ans<<endl;
	}
	return 0;
}