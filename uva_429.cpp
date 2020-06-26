#include<bits/stdc++.h>
using namespace std;
#define pb push_back
std::map<string, vector<string> >adjlist;
std::map<string, int> visited,dist;
std::vector<string> nodes;

bool find_len(string a,string b){
	int cnt=0;
	if(a.length()!=b.length()) return false;
	for (int i = 0; i < a.length(); ++i)
	{
		if(a[i]!=b[i]) cnt++;
	}
	//cnt += (abs(a.length()-b.length()));
	if(cnt==1) return true;
	return false;
}


void bfs(string a){
	visited[a] = true;
	//dist[a] = 0;
	queue<string>q;
	q.push(a);
	while(!q.empty()){
		string x = q.front();
		q.pop();
		for (int i = 0; i < adjlist[x].size(); ++i)
		{
			if(!visited[adjlist[x][i]]){
				dist[adjlist[x][i]] =1+dist[x] ;
				visited[adjlist[x][i]] = 1;
				q.push(adjlist[x][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string s;
		adjlist.clear();
		nodes.clear();
		cin>>s;
		while(s!="*"){
			nodes.pb(s);
			cin>>s;
		}
		for (int i = 0; i < nodes.size()-1; ++i)
		{
			for (int j = i+1; j < nodes.size(); ++j)
			{
				if(find_len(nodes[i],nodes[j])){
					adjlist[nodes[i]].pb(nodes[j]);
					adjlist[nodes[j]].pb(nodes[i]);
				}
			}
		}
		/*for(map<string, std::vector<string> >::iterator it = adjlist.begin();it!=adjlist.end();it++){
			cout<<it->first<<" ";
			for (int i = 0; i < adjlist[it->first].size(); ++i)
			{
				cout<<adjlist[it->first][i]<<" ";
			}
			cout<<endl;
		}*/
		string start,to,line;
    	size_t pos;
    	getline(cin,line);
    	getline(cin,line);
    	while(line != ""){
     		pos = line.find(" ");
      		start = line.substr(0,pos);
      		to = line.substr(pos+1,line.size());
      		visited.clear();
      		dist.clear();
      		bfs(start);
      		cout<<start<<" "<<to<<" "<<dist[to]<<endl;
      		if(!getline(cin,line))
        		break;
    	}
		if(t!=0) cout<<endl;

	}
	return 0;
}