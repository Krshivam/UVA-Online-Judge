#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<std::vector<int> > adjlist(n+1);
		std::vector<int> clr(n+1,-1);
		int colocnt[2];
		for (int i = 0; i < n; ++i)
		{
			int l,u;
			cin>>l;
			for (int j = 0;j <l; ++j)
			{
				cin>>u;
				if(u<=n && u>=1){
					adjlist[i].pb(u-1);
					adjlist[u-1].pb(i);
				}
				
			}
		}
		int ans=0;
		//int cnt=0;
		queue<int>q;	
		for (int i = 0; i < n; ++i)
		{
			colocnt[0]=0;
			colocnt[1] = 0;
			bool bt = true;
			if(clr[i]==-1){
				clr[i] = 0;
				colocnt[0]++;
				q.push(i);
				while(!q.empty()){
					int d = q.front();
					q.pop();
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
				if(bt) ans += max(colocnt[0],colocnt[1]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}