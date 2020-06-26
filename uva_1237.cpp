#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t){
		int n,x,y;
		std::map<pair<int,int>, string> m;
		cin>>n;
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin>>s>>x>>y;
			m[mp(x,y)] = s;
		}
		int q
		cin>>q;
		for (int i = 0; i < q; ++i)
		{
			int z;
			int cnt=0;
			cin>>z;
			std::vector<string> v;
			for(map<pair<int,int>, string>::iterator it=m.begin();it!=m.end();it++){
				if(z<=(it->first).second && z>=(it->first).first) cnt++,v.push_back(it->second);
			}
			if(cnt>1 || cnt==0){
				cout<<"UNDETERMINED"<<endl;
			}
			else cout<<v[0]<<endl;
		}
			t-=1;
			if(t!=0){
				cout<<endl;
			}
			
		
		
	}
	return 0;
}