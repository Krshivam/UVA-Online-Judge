#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::map<string, std::vector<string> > adjlist;
std::map<string, int>visited,dist;
std::map<string, string>parent;

void bfs(string a,string b){
	queue<string>q;
	q.push(a);
	dist[a] = 0;
	visited[a] = 1;
	while(!q.empty()){
		string node = q.front();
		q.pop();
		for (int i = 0; i < adjlist[node].size(); ++i)
		{
			if(!visited[adjlist[node][i]]){
				visited[adjlist[node][i]] = 1;
				q.push(adjlist[node][i]);
				dist[adjlist[node][i]] = dist[node]+1;
				parent[adjlist[node][i]] = node;
			}
		}
	}
	string x =b;
	if(!parent.count(b)){
		cout<<"No route"<<endl;
		return ;
	}
	std::vector<string> v;
	while(b!=a){
		v.pb(b);
		b = parent[b];
	}
	v.pb(a);
	for (int i = v.size()-1; i>0 ; i--)
	{
		cout<<v[i]<<" "<<v[i-1]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	//cout<<"f";
	int x=1;
	while(cin>>n){
		adjlist.clear();
		//cout<<"vnv";
		visited.clear();
		parent.clear();
		dist.clear();
		for (int i = 0; i < n; ++i)
		{
			string a,b;
			cin>>a>>b;
			//cout<<"hekfwd";
			adjlist[a].pb(b);
			adjlist[b].pb(a);
		}
		//cout<<"hello";

		string a,b;
		cin>>a>>b;
		if(x>1) cout<<endl;
		bfs(a,b);
		x++;
	}
	return 0;
}