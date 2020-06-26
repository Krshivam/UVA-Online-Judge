#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
	int n;
	int kase=1;
	while(cin>>n){
		int arr[n+1];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		ll ans=arr[0];
		for (int i = 0; i < n-1; ++i)
		{
			ll t=arr[i];
			for (int j= i+1; j < n; ++j)
			{
				t*=1LL*arr[j];
				ans = max(ans,t);
				ans = max(ans,1LL*arr[j])	;
			}
			ans = max(ans,t);
		}
		ans = max(ans,1LL*0);
		cout<<"Case #"<<kase<<": The maximum product is "<<ans<<"."<<endl;
		kase++;
		cout<<endl;
	}
	return 0;
}