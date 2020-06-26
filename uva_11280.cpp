#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back 
#define pii pair<int,int>

std::vector<std::vector<pii> >adjList;
std::map<string, int>decode;
std::map<int, int> table,visited;

int n;

void dfs(int strt,int cnt,int sm){
	visited[strt] = 1;
	if(strt==n-1){
		if(table.count(cnt) && table[cnt]>sm){
			table[cnt] = sm;
		}
		else table[cnt] = sm;
	}
	
	for (int i = 0; i < adjList[strt].size(); ++i)
	{
		if(!visited[adjList[strt][i].first]){
			dfs(adjList[strt][i].first,cnt+1,sm+adjList[strt][i].second);
		}
	}
	visited[strt] = 0;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		
		cin>>n;
		adjList.clear();
		adjList.resize(n);
		decode.clear();
		table.clear();
		visited.clear();
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			decode[s] = i;
		}
		int e;
		cin>>e;
		for (int i = 0; i <e ; ++i)
		{
			string a,b;
			int w;
			cin>>a>>b>>w;
			adjList[decode[a]].pb(mp(decode[b],w));
		}
		int q;
		cin>>q;
		dfs(0,-1,0);
		while(q--){
			int d;
			cin>>d;
			cout<<table[d];
		}
	}
	return 0;
}