#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main(int argc, char const *argv[])
{
	std::vector<ll> v;
	for (int i = 0; i <=9999; ++i)
	{
		v.pb(i*i);
	}
	int n;
	while(cin>>n){
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]>pow(10,n)){
				break;
			}
			int l = v[i]/pow(10,n/2);
			int u = v[i]%pow(10,n/2);
			if(pow(l+u,2)==v[i]){
				cout<<setw(n)<<setfill("0")<<v[i]<<endl;
			}
		}
	}
	return 0;
}