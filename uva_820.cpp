#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

std::vector<std::vector<int> >adjList,capacity;
std::vector<int>parent;
int s,t,c;
int n;


int bfs(){
	fill(parent.begin(), parent.end(),-1);
	parent[s] = -2;
	queue<pii>q;
	q.push(mp(s,99999));
	while(!q.empty()){
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(int i=0;i<adjList[cur].size();i++){
			if(parent[adjList[cur][i]]==-1 && capacity[cur][adjList[cur][i]]){
				parent[adjList[cur][i]] = cur;
				int new_flow = min(flow,capacity[cur][adjList[cur][i]]);
				if(adjList[cur][i]==t){
					return new_flow;
				}
				q.push(mp(adjList[cur][i],new_flow));
			}
		}
	}
	return 0;
}


int max_flow(){
	int flow=0;
	int new_flow;
	while(new_flow=bfs()){
		flow+=new_flow;
		int cur = t;
		//cout<<"shgs";
		while(cur!=s){
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			//cout<<"fbhj";
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
		//new_flow=0;
	}
	return flow;
}

int main(int argc, char const *argv[])
{
	int kase=1;
	cin>>n;
	while(n){
		cin>>s>>t>>c;
		adjList.clear();
		parent.clear();
		parent.resize(n+1);
		adjList.resize(n+1);
		capacity.clear();
		capacity.resize(n+1,std::vector<int> (n+1));
		for (int i = 0; i <n+1; ++i)
		{
			for (int j = 0; j < n+1; ++j)
			{
				capacity[i][j]=0;
			}
		}
		for (int i = 0; i < c; ++i)
		{
			int u,v,d;
			cin>>u>>v>>d;
			adjList[u].pb(v);
			adjList[v].pb(u);
			capacity[u][v] += d;
			capacity[v][u] += d;
		}
		cout<<"Network "<<kase<<endl;
		cout<<"The bandwidth is "<<max_flow()<<"."<<endl;
		kase++;
		cin>>n;
		cout<<endl;
	}
	return 0;
}