#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[])
{
	string s;
	while((cin>>s) && s!="."){
		string s1;
		int n=s.length();
		int u=0;
		std::vector<int> v;
		for (int j = 1; j*j <= n; ++j)
		{
			if(n%j==0) {
				v.pb(j);
				if(j*j!=n) v.pb(n/j);
			}
		}
		sort(v.begin(),v.end());
		//cout<<v.size()<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			string s1 = s.substr(0,v[i]);
			int x = v[i];
			int b=0;
			while(x<n){
				if(s.substr(x,v[i])!=s1) {
					b=1;
					break;
				}
				else x+=v[i];
			}
			if(!b) {
				cout<<n/v[i]<<endl;
				u=1;
				break;
			}
		}
		if(!u) cout<<1<<endl;
	}
	return 0;
}