#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
std::vector<std::vector<int> > network;
std::vector<int> tin,tout,visited;
std::map<pair<int,int>,int> bridges;
int timer =0;

void findBridge(int x,int p=-1){
	tin[x] = tout[x] = ++timer;
	visited[x] = 1;
	for (int i = 0; i < network[x].size(); ++i)
	{
		if(network[x][i]==p) continue;
		if(visited[network[x][i]]){
			tout[x] = min(tout[x],tin[network[x][i]]);
		}
		else{
			findBridge(network[x][i],x);
			tout[x] = min(tout[x],tout[network[x][i]]);
			if(tout[network[x][i]]>tin[x]){
				if(x<network[x][i]) bridges[mp(x,network[x][i])] = 1;
				else bridges[mp(network[x][i],x)] = 1;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n;
	
	while(cin>>n){
		network.clear();
		visited.clear();
		network.resize(n+5);
		tin.clear();
		tout.clear();
		bridges.clear();
		//parent.clear();
		tin.resize(n+5,0);
		tout.resize(n+5);
		//bridges.resize(n+5);
		visited.resize(n+5,0);
		timer=0;
		string s;
		getline(cin,s);
		for (int i = 0; i < n; ++i)
		{
			int t=0;
			getline(cin,s);
			for (int j = 1; j < s.length(); ++j)
			{
				if(s[j]==' ') continue;
				else if(s[j]=='(') t=1;
				else if(s[j]==')') t=0;
				else if(!t) network[s[0]-'0'].pb(s[j]-'0');
			}
			//cout<<endl;
		}
		for (int i = 0; i < n; ++i)
		{
			if(!visited[i]){
				//dfsroot=i;
				//rootchild = 0;
				findBridge(i);
			}
		}
		cout<<bridges.size()<<" critical links"<<endl;

		for(std::map<pair<int,int>, int>::iterator  it=bridges.begin();it!=bridges.end();it++){
			cout<<(it->first).first<<" - "<<(it->first).second<<endl;
		}
		cout<<endl;
		//cin>>n;
	}
	return 0;
}