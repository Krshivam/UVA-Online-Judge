#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string arr[55];
		//int new_arr[55][55];
		for (int i = 0; i <n ; ++i)
		{
			cin>>arr[i];
		}
		//int ans = 1e9;
		//cout<<ans;
		int mn = 1e9;
		for (int i = 0; i < n; ++i)
		{
			int mn = 1e9;
			for (int j = 0; j < m; ++j)
			{
				int ans=0;
				int t=1e9;
				int mnr = 1e9;
				if(arr[i][j]=='0'){
					
					for (int k = 0; k <n ; ++k)
					{
						int v = 1e9;
						if(k!=i){
							for (int l = 0; l < m; ++l)
							{
								if(arr[k][l]=='0'){
									v = min(v,abs(l-j));
								}
							}
							t = min(v,t);
							ans+=t;
							mnr = min(mnr,ans);
						}
						mn = min(mn,mnr);
					}
					
				}
				
			}
			
		}

		if(mn>=1e9) cout<<-1<<endl;
		else cout<<mn<<endl;
	}
	return 0;
}