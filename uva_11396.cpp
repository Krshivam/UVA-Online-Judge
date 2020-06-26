#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<int> visited;
std::vector<int> clr;
#define pb push_back



int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		//n = (n*3)/2;
		adjlist.clear();
		visited.clear();
		clr.clear();
		adjlist.resize(n+10);
		visited.resize(n+10,0);
		clr.resize(n+10,-1);
		int u,v;
		while((cin>>u>>v)&&u)
		
		{
			adjlist[u-1].pb(v-1);
			adjlist[v-1].pb(u-1);
		}
		queue<int>q;
		q.push(0);
		clr[0] = 0;
		int x=0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for (int i = 0; i < adjlist[node].size(); ++i)
			{
				if(clr[adjlist[node][i]]==-1){
					clr[adjlist[node][i]] = 1-clr[node];
					q.push(adjlist[node][i]);
				}
				else if(clr[adjlist[node][i]]==clr[node]){
					x=1;
					break;
				}
			}
		}
		if(x){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}