#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::map<char, std::vector<char> > adjlist;
std::map<char, int> visited;
std::vector<char> track;


void dfs(char x){
	visited[x] = 1;
	for (int i = 0; i < adjlist[x].size(); ++i)
	{
		if(!visited[adjlist[x][i]]){
			dfs(adjlist[x][i]);
		}
	}
	track.pb(x);
}

int main(int argc, char const *argv[])
{
	string s,s1;
	cin>>s;
	while((cin>>s1)&& s1!="#"){
		for (int i = 0; i < s1.length() && i<s.length(); ++i)
		{
			if(s[i]!=s1[i]){
				adjlist[s[i]].push_back(s1[i]);
				break;
			}
		}
		s=s1;
	}
	for (std::map<char, std::vector<char> >::iterator it=adjlist.begin();it!=adjlist.end();it++)
	{
		//cout<<it->first<<endl;
		if(!visited[it->first]){
			dfs(it->first);

		}
	}
	for (int i = track.size()-1;i>=0;i--)
	{
		cout<<track[i];
	}
	cout<<endl;
	return 0;
}

