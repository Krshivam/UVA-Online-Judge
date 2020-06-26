#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,m;
std::unordered_map<string, std::vector<string> > graph;
std::map<string, int>tin,tlow,visited;
int timer=0;
stack<string>stck;


void findSCC(string s){
	tin[s] = tlow[s] = ++timer;
	visited[s]=1;
	stck.push(s);
	for (int i = 0; i < graph[s].size(); ++i)
	{
		if(!visited[graph[s][i]]){
			findSCC(graph[s][i]);
		}
		if(visited[graph[s][i]]){
			tlow[s] = min(tlow[s],tlow[graph[s][i]]);
		}
	}
	if(tlow[s]==tin[s]){
		while(1){
			string s1 = stck.top();
			//visited[s1]=0;
			stck.pop();
			if(s1==s) cout<<s<<break;
			else cout<<s1<<", ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int kase=1;
	while((cin>>n>>m)&&n){
		string s1,s2;
		tin.clear();
		tlow.clear();
		visited.clear();
		graph.clear();
		for (int i = 0; i < m; ++i)
		{
			cin>>s1>>s2;
			graph[s1].pb(s2);
		}
		cout<<"Calling circles for data set "<<kase<<":"<<endl
		for (std::unordered_map<string, std::vector<string> >::iterator it = graph.begin(); it!=graph.end();it++)
		{
			if(!visited[it->first]){
				findSCC(it->first);
			}
		}
		cout<<endl;
	}
	return 0;
}