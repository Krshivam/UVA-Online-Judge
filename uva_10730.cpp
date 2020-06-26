#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		char x;
		cin>>x;
		int arr[n+1];
		std::map<int, int> m;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			m[arr[i]] = i;
		}
		int bl=0;
		int seen[n];
		for (int i = 0; i < n-2; ++i)
		{
			memset(seen,0,sizeof(seen));
			for (int j = 0; j <=i; ++j)
			{
				seen[arr[j]]=1;
			}
			for (int j = i+1; j < n-1; ++j)
			{
				//cout<<arr[i]+2*(arr[j]-arr[i])<<endl;
				seen[arr[j]]=1;
				int x= arr[j]+arr[j]-arr[i];
				if(x>=0 && x<n){
					if(!seen[x]){
						bl=1;
					cout<<"no"<<endl;
					break;
					}
				}
			}
			if(bl) break;
			
		}
		if(!bl) cout<<"yes"<<endl;
	}
	return 0;
}