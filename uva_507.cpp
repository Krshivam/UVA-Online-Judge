#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		for (int i = 2; i <= n; ++i)
		{
			cin>>arr[i];
		}
		ll ans=0;
		ll mx=0;
		int id1=0,x=-2,y=-3;
		//std::vector<pair<int,int> >v;
		for (int i = 2; i <=n; ++i)
		{
			ans+=arr[i];
			if(ans<0)  id1=i,ans=0;
			if(mx<=ans){
				if(ans>mx || (ans==mx && (i-id1 > y-x))) {
					y = i;
					x = id1;
				}
				mx = ans;
			}
			
			
			//if(ans<0) ans=0;
		}
		if(mx==0) cout<<"Route "<<kase<<" has no nice parts"<<endl;
		else cout<<"The nicest part of route "<<kase<<" is between stops "<<x<<" and "<<y<<endl;
		kase++;
	}
	return 0;
}
