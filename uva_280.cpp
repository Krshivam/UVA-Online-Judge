#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int cnt;
std::vector<std::vector<int> > adjlist;
std::vector<int> visited;
int n;


void dfs(int x){
	
	for(int i=0;i<adjlist[x].size();i++){
		if(!visited[adjlist[x][i]]){
			visited[adjlist[x][i]] = true;
			dfs(adjlist[x][i]);
		}
		
	}

}

int main(int argc, char const *argv[])
{
	
	while((cin>>n)&&n){
		int u,v;
		adjlist.clear();
		adjlist.resize(n);
		while((cin>>u)&&u){
			while((cin>>v)&&v){
				adjlist[u-1].pb(v-1);
			}
		}
		int t;
		cin>>t;
		int x;
		while(t--){
			cin>>x;
			visited.clear();
			cnt = 0;
			visited.resize(n);
			dfs(x-1);
			cnt+= count(visited.begin(), visited.end(),0);
			printf("%d",cnt);
    
    		for(int i=0;i<n;i++) if(!visited[i]) printf(" %d",i+1);
    			printf("\n");
		}
	}
	return 0;
}