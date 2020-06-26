#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::map<char, std::vector<char> > adjlist;
std::map<char, int>visited;
std::map<char, double>wt,dist;

void bfs(char node){
	visited[node] = 1.0;
	dist[node] = 0;
	queue<char>q;
	q.push(node);
	while(!q.empty()){
		char x = q.front();
		q.pop();
		for (int i = 0; i < adjlist[x].size(); ++i)
		{
			if(!visited[adjlist[x][i]]){
				visited[adjlist[x][i]] = 1;
				dist[adjlist[x][i]] = dist[x]+1.0;
				q.push(adjlist[x][i]);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		adjlist.clear();
		visited.clear();
		dist.clear();
		wt.clear();
		for (int i = 0; i < n; ++i)
		{
			char x;
			double d;
			cin>>x>>d;
			string s;
			wt[x] = d;
			cin>>s;
			for (int j = 0; j < s.length(); ++j)
			{
				if(s[j]==' ') continue;
				if(s[j]=='*') adjlist[x].pb('e'),adjlist['e'].pb(x);
				else adjlist[x].pb(s[j]);
			}
		}
		double mx = -9999999.00;
		char c;
		bfs('e');
		for (map<char, double>::iterator it=wt.begin();it!=wt.end();it++)
		{
			//cout<<it->first<<" "<<wt[it->first]-0.05*dist[it->first]<<" "<<dist[it->first]<<endl;
			if(wt[it->first]-0.05*dist[it->first]>=mx){
				if(wt[it->first]-0.05*dist[it->first]-mx<=1e-9 && c>it->first){
					//mx = wt[it->first]-0.05*dist[it->first];
					c = it->first;
				}
				else if(wt[it->first]-0.05*dist[it->first]>mx) {
					mx = wt[it->first]-0.05*dist[it->first];
					c = it->first;
				}
			}
		}
		cout<<"Import from "<<c<<endl;
	}
	return 0;
}