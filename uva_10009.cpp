#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::map<string, std::vector<string> >adjList;
std::map<string,int>visited,dist;
std::map<string, string>parent;



void bfs(string src,string dest){
	queue<string>q;
	q.push(src);
	visited[src] = 1;
	//dist[src] = 0;
	parent[src] = src;
	while(!q.empty()){
		string x = q.front();
		q.pop();
		for (int i = 0; i < adjList[x].size(); ++i)
		{
			if(!visited[adjList[x][i]]){
				parent[adjList[x][i]] = x;
				visited[adjList[x][i]] = 1;
				q.push(adjList[x][i]);
			}
		}
	}
	//cout<<parent[dest];
	string s="";
	while(dest!=src){
		s+=dest[0];
		dest = parent[dest];
	}
	s+=src[0];
	for (int i = 0; i < s.length(); ++i)
	{
		cout<<s[s.length()-i-1];
	}
	cout<<endl;
}



int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		adjList.clear();
		for (int i = 0; i < n; ++i)
		{
			string a,b;
			cin>>a>>b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		for (int i = 0; i < m; ++i)
		{
			string a,b;
			cin>>a>>b;
			visited.clear();
			parent.clear();
			bfs(a,b);
		}
		if(t!=0) cout<<endl;
	}
	return 0;
}