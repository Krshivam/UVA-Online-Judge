#include<bits/stdc++.h>
using namespace std;
#define pb push_back


void bfs(std::vector<int>&degree,std::vector<std::vector<int> > &g,std::vector<int> &top_order){
	priority_queue<int,std::vector<int>,greater<int> >q;
	for (int i = 0; i < degree.size(); ++i)
	{
		if(degree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u = q.top();
		q.pop();
		top_order.pb(u);
		for(int i=0;i<g[u].size();i++){
			degree[g[u][i]]--;
			if(degree[g[u][i]] ==0){
				q.push(g[u][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	int id=1;
	while(cin>>n){
		std::vector<std::vector<int> >g(n);
		std::map<string, int> m;
		std::map<int, string> m1;
		std::vector<int> degree(n,0);
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin>>s;
			m[s] = i;
			m1[i] = s;
		}
		int e;
		cin>>e;
		string x,y;
		for (int i = 0; i < e; ++i)
		{
			cin>>x>>y;
			g[m[x]].pb(m[y]);
			degree[m[y]]++;
		}
		
		
		//cout<<endl;
		/*for (int i = 0; i < n; ++i)
		{
			cout<<degree[i]<<" ";
		}
		cout<<endl;*/
		std::vector<int> top_order;
		bfs(degree,g,top_order);
		cout<<"Case #"<<id<<": Dilbert should drink beverages in this order:";
		for (int i = 0; i < top_order.size(); ++i)
		{
			cout<<" "<<m1[top_order[i]];
		}

		cout<<"."<<endl<<endl;
		id++;
	}
	return 0;
}