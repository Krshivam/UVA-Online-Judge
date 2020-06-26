#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
		int n = s.size();
		string s2 = "";
		for (int i = n/2; i>=0; i-- )
		{
			if(s[i]!=s[n-i-1]) s2+=s[i];
		}
		cout<<s<<s2;
	}
	return 0;
}