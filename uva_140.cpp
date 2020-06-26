#include<bits/stdc++.h>
using namespace std;
std::map<int, std::vector<int> >adjList;

int main(int argc, char const *argv[])
{
	string s;
	while((cin>>s)&&s!="#"){
		int c1=0;
		int c2=0;
		int x;
		for (int i = 0; i < s.length(); ++i)
		{
			if(!c1 && !c2) {
				x = (s[i]-65)+1;
				c1=1;
			}
			else if(s[i]==':') continue;
			else if(s[i]==';'){
				c1=0;
				c2=0;
			}
			else{
				int nd = (s[i]-65)+1;
				adjList[c1].pb(nd);
				adjList[nd].pb(c1);
			}
		}
		
	}
	return 0;
}