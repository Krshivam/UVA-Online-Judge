#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int i;
	for ( i = 0; i < t; ++i)
	{
		string s;
		cin>>s;
		string s1,s2;
		int n=s.length();
		std::map<string, int> m;
		int u=0;
		for (int j = 1; j < n; ++j)
		{
			int b=0;
			s1 = s.substr(0,j);
			int x=j;
			if(n%j==0){
				while(x<n){
					if(s.substr(x,j)!=s1) {
						b=1;
						break;
					}
					else x+=j;
				}
				if(!b) {
					cout<<j<<endl;
					u=1;
					break;
				}
			}
		}
		if(!u) cout<<n<<endl;
		if(i!=t-1) cout<<endl;
	}
	return 0;
}