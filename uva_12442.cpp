#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::vector<std::vector<int> > adjlist;
std::vector<int> visited;
std::vector<int> c;
int n;
int d;

void dfs(int x){
	//if(visited[x]) return 1;
	visited[x] = 1;
	//int ans = 0;
	for (int i = 0; i < adjlist[x].size(); ++i)
	{
		if(!visited[adjlist[x][i]]){
			dfs(adjlist[x][i]);
		}
	}
	visited[x] = 0;
	d++;
	//return c[x] = ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase = 1;
	while(t--){
		//int n;
		cin>>n;
		visited.clear();
		adjlist.clear();
		visited.resize(n,0);
		adjlist.resize(n);
		c.clear();
		c.resize(n,-1);
		int u,v;
		for (int i = 0; i <n ; ++i)
		{
			cin>>u>>v;
			adjlist[u-1].pb(v-1);
		}
		int vertex;
		int cnt = 0;
		d=0;
		for(int i=0;i<n;i++){
			if(c[i]==-1){
				dfs(i);
			}
				
				//cout<<d<<endl;
			if(cnt<d){
				cnt = d;
				vertex = i;
			}
			d=0;
		}
		//cout<<visited[0]<<" "<<visited[1]<<" "<<visited[2]<<endl;
		cout<<"Case "<<kase<<": "<<vertex+1<<endl;
		kase++;
	}
	return 0;
}