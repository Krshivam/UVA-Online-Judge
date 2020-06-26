#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+5;

int main(int argc, char const *argv[])
{
	int n,q;
	
	cin>>n>>q;
	string arr[n+1];
	int idx;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < q; ++i)
	{
		string s1;
		cin>>s1;
		int mx=inf;
		
		for (int l = 0; l < n; ++l)
		{
			int min1 = inf;
			if(s1.length()>arr[l].length()) continue;
			
			for (int j = 0; j < arr[l].length()-s1.length()+1; ++j)
			{
				int cnt=0;
				for (int k = 0; k <s1.length() ; ++k)
				{
					if(arr[l][k+j]!=s1[k]) cnt++;
				}
				min1 = min(min1,cnt);
			}
			if(mx>min1){
				mx = min1;
				idx=l;
			}
		}
		cout<<idx+1<<endl;
	}

	return 0;
}