#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<std::vector<int> > adjlist(n+1);
		std::vector<int> clr(n+1,-1);
		int colocnt[2];
		//cout<<clr[n]<<endl;
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			cin>>u>>v;
			adjlist[u].pb(v);
			adjlist[v].pb(u);
		}
		int ans=0;
		//int cnt=0;
		queue<int>q;
		bool bt = true;	
		for (int i = 0; i < n && bt; ++i)
		{
			colocnt[0]=0;
			colocnt[1] = 0;
			
			int x=0;
			if(clr[i]==-1){
				clr[i] = 0;
				colocnt[0]++;
				q.push(i);
				while(!q.empty()){
					int d = q.front();
					q.pop();
					x++;
					for (int i = 0; i < adjlist[d].size(); ++i)
					{
						if(clr[adjlist[d][i]]==-1){
							colocnt[1-clr[d]]++;
							clr[adjlist[d][i]] = 1-clr[d];
							q.push(adjlist[d][i]);
						}
						else if(clr[adjlist[d][i]]==clr[d]){
							bt = false;
							break;
						}
					}
				}
				if(x==1) ans+=1;
				else if(bt) ans +=min(colocnt[0],colocnt[1]);
			}
		}
		if(!bt) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}