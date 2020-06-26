#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int cnt(string s){
	int cn =0;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]==',') cn++;
	}
	return cn;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		int n;
		cin>>n;
		string s1;
		cin>>s1;
		int u,v,d;
		std::vector<pair<int,pair<int,int> > > g(n);
		std::vector<pair<int,pair<char,char> > >parent;
		
		for (int i = 0; i < n; ++i)
		{
			string s;
			//cin>>s3;
			getline(cin,s);
			std::vector<string> v1;
			//cout<<s.length()<<endl;
			//cout<<s3<<endl;
			if(cnt(s)!=n-1) v1.push_back("0");
			int j=0;
			string s2="";
			while(j<s.length()){
				if(s[j]==',') {
					j+=2;
					v1.pb(s2);
					s2="";
				}
				//if(s[j]=='\0') v1.pb("0");
				else s2+=s[j],j++;
			}
			v1.pb(s2);
			for (int j = 0; j <v1.size() ; ++j)
			{
				int x=0;
				stringstream f(v1[j]);
				f>>x;
				if(i!=j && x!=0){
					g.pb(mp(x,mp(i,j)));
				}
				
			}
		}
		sort(g.begin(), g.end());
		std::vector<int> tree(n);
		for (int i = 0; i <n; ++i)
		{
			tree[i] = i;
		}
		int start = 'A';
		//std::vector<pair<int,int>> v;
		for (int i = 0; i < g.size(); ++i)
		{
			int a=g[i].first;
			int b = g[i].second.first;
			int c = g[i].second.second;

			if(tree[b]!=tree[c]){
				//cout<<a<<endl;
				parent.pb(mp(a,mp(start+b,start+c)));
				int id = tree[c];
				for (int j = 0; j < n; ++j)
				{
					if(tree[j]==id){
						tree[j] = tree[b];
					}
				}
			}
		}
		sort(parent.begin(), parent.end());
		cout<<"Case "<<kase<<":"<<endl;
		for (int i = 0; i <parent.size() ; ++i)
		{
			cout<<parent[i].second.first<<"-"<<parent[i].second.second<<" "<<parent[i].first<<endl;
		}
		kase++;
	}
	return 0;
}