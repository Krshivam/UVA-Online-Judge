#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,m;
std::map<string, std::vector<string> > network;
std::vector<string> cities;
std::map<string, int> tin,tlow;
std::map<string, string> parent;
std::map<string, int> ap;
int timer=0;
string dfsroot;
int rootchild;

void findArticulation(string s){
	tin[s] = tlow[s] = ++timer;
	for (int i = 0; i <network[s].size() ; ++i)
	{
		if(tin[network[s][i]]==0)  {
			parent[network[s][i]] = s;
			if(s==dfsroot) rootchild++;
			findArticulation(network[s][i]);
			if(tlow[network[s][i]]>=tin[s]){
				ap[s] = 1;
			}
			tlow[s] = min(tlow[s],tlow[network[s][i]]);
		}
		else if(network[s][i]!=parent[s]){
			tlow[s] = min(tlow[s],tin[network[s][i]]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int kase=1;
	cin>>n;
	while(n){
		network.clear();
		parent.clear();
		ap.clear();
		cities.clear();
		tin.clear();
		tlow.clear();
		timer=0;
		//network.resize(n+5);
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin>>s;
			cities.pb(s);
		}
		int m;
		cin>>m;
		string x,y;
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			network[x].pb(y);
			network[y].pb(x);
		}
		for(int i=0;i<cities.size();i++){
			if(!tin[cities[i]]){
				dfsroot = cities[i];
				rootchild = 0;
				findArticulation(cities[i]);
				if(rootchild>1){
					ap[cities[i]] = 1;
				}
			}
		}
		cout<<"City map #"<<kase<<": "<<ap.size()<<" camera(s) found"<<endl;
		for(std::map<string, int>::iterator  it=ap.begin();it!=ap.end();it++){
			cout<<it->first<<endl;
		}
		kase++;
		cin>>n;
		if(n!=0) cout<<endl;
		//cout<<endl;
	}

	return 0;
}