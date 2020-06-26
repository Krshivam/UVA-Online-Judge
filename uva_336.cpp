#include<bits/stdc++.h>
using namespace std;
#define pb push_back
map<int, vector<int> >adjlist;
std::map<int, int>dist,visited;
std::map<int, int>k;


int  bfs(int x,int d){
	visited[x] = 1;
	dist[x] = 0;
	queue<int>q;
	q.push(x);
	int cnt=0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		
			for (int i = 0; i < adjlist[f].size(); ++i)
		{
			if(!visited[adjlist[f][i]] && 1+dist[f]<=d){
				dist[adjlist[f][i]] = 1+dist[f];
				visited[adjlist[f][i]] = 1;
				cnt++;
				q.push(adjlist[f][i]);
			}
		}
		
		
	}
	//cout<<cnt<<endl;
	//cout<<adjlist.size();
	//if(cnt==0) return 0;
	//cout<<cnt<< " "<<adjlist.size()<<endl;
	//if(cnt==0) return adjlist.size();
	//if(!k[a]) cout<<k.size()
	return adjlist.size()-cnt-1;
}

int main(int argc, char const *argv[])
{
	int n;
	int kase=1;
	while((cin>>n)&&n){
		int a,b;
		adjlist.clear();
		//adjlist.resize(10005);

		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b;
			adjlist[a].pb(b);
			
			adjlist[b].pb(a);
			k[a] = 1;
			k[b] = 1;
		}
		while((cin>>a>>b)){
			if(a==0 && b==0) break;
			visited.clear();
			dist.clear();
			if(adjlist.count(a)==0){
				cout<<"Case "<<kase<<": "<<adjlist.size()<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
			}
			else cout<<"Case "<<kase<<": "<<bfs(a,b)<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
			kase++;
		}
	}
	return 0;
}