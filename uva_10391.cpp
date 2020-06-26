#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[])
{
	std::map<string, int> m,m1;
	//cin>>m>>m1;
	string s,s1,s2;
	std::vector<string> v,result;
	while(cin>>s){
		v.pb(s);
		m[s]+=1;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		for(int j=1;j<v[i].size();j++){
			s1 = v[i].substr(0,j);
			s2 = v[i].substr(j,v[i].size()-j);
			if(m[s1] && m[s2] && !m1[v[i]]){
				result.pb(v[i]);
				m1[v[i]]+=1;
			}
		}
	}
	sort(result.begin(),result.end());
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}