#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n,m;
	while((cin>>n>>m)&&n){
		//int l=-1,r=-1;
		int l[n+1],r[n+1];
		for (int i = 1; i <=n; ++i)
		{
			l[i] = i-1;
			r[i] = i+1;
		}
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			cin>>u>>v;
			if(l[u]==0) cout<<'*'<<" ";
			else cout<<l[u]<<" ";
			if(r[v]>n) cout<<'*';
			else cout<<r[v];
			l[r[v]] = l[u];
			r[l[u]] = r[v];
			cout<<endl;
		}
		cout<<'-'<<endl;

	}
	return 0;
}