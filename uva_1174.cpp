#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
struct node{
	string u,v;
	int d;
};

bool compare(node a,node b){
	return a.d<b.d;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		std::map<string, int>decode;
		int parent[100000];
		node edgelist[2005];
		memset(parent,0,sizeof(parent));
		//decode.clear();
		int n,m;
		cin>>n>>m;
		int ct=1;
		for (int i = 0; i < m; ++i)
		{
			string u1,v1;
			int d1;
			cin>>u1>>v1>>d1;
			edgelist[i].u = u1;
			edgelist[i].v = v1;
			edgelist[i].d = d1;
			if(!decode[u1]) decode[u1] = ct,parent[ct]=ct,ct++;
			if(!decode[v1]) decode[v1] = ct,parent[ct]=ct,ct++;
		}
		int cost=0;
		sort(edgelist,edgelist+m,compare);
		for(int i=0;i<m;i++){
			if(parent[decode[edgelist[i].u]]!=parent[decode[edgelist[i].v]]){
				cost+=edgelist[i].d;
			}
			int o_id = parent[decode[edgelist[i].u]];
			int n_id = parent[decode[edgelist[i].v]];
			for (int i = 0; i < m+10; ++i)
			{
				if(parent[i]==o_id) parent[i] = n_id;
			}
		}
		cout<<cost<<endl;
		if(t!=0) cout<<endl;
	}
	return 0;
}