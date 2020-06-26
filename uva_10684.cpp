#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		int mx=0,ans=0;
		for (int i = 0; i < n; ++i)
		{
			ans+=arr[i];
			mx = max(mx,ans);
			if(ans<0) ans=0;
		}
		if(mx==0) cout<<"Losing streak."<<endl;
		else cout<<"The maximum winning streak is "<<mx<<"."<<endl;

	}
	return 0;
}