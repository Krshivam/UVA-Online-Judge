#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string s;
		std::map<string,int>m;
		int cnt=0;
		while(getline(cin,s)){
			if(s=="") break;
			m[s]+=1;
			cnt++;
			//cout<<s<<endl;
		}
		for(std::map<string, int>::iterator it=m.begin();it!=m.end();it++){
			//cout<<it->first<<endl;
			double val = (m[it->first]*100.0)/(cnt*1.0);
			cout<<it->first<<" ";
			printf("%0.4f\n", val);

		}
		if(t!=1) cout<<endl;
	}
	return 0;
}