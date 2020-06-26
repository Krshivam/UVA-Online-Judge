#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::map<char, double>m;
		for (int i = 0; i < n; ++i)
		{
			char x;
			double d;
			cin>>x>>d;
			//d = d*1.0 / 100;
			m[x] = d;
		}
		cin.ignore();
		int k;
		cin>>k;
		k++;
		double ans=0.0;
		while(k--){
			string s;
			getline(cin,s);
			
			for (int i = 0; i < s.length(); ++i)
			{
				if(m.count(s[i])) ans+=m[s[i]];
			}
		}
		ans = ans*1.0/100.0;
		printf("%0.2f%s\n", ans,"$");
	}
	return 0;
}