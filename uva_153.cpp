#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	while((cin>>s) && s!="#"){
		std::map<char, int> m;
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = i+1; j < s.length(); ++j)
			{
				m[s[j]]++;
			}
			
		}

		
	}
	return 0;
}