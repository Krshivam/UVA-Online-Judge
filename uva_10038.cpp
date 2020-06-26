#include<bits/stdc++.h>
using namespace std;
int arr[3001],arr1[3001];

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		memset(arr1,0,sizeof(arr1));
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			//arr1[i] = 0;
		}
		for (int i = 0; i < n-1; ++i)
		{
			if(abs(arr[i]-arr[i+1])<n) arr1[abs(arr[i]-arr[i+1])] = 1;
		}
		int cnt=0;
			for (int i = 1; i < n; ++i)
			{
				cnt+=arr1[i];
			}
			if(cnt==n-1){
				cout<<"Jolly"<<endl;
			}
			else cout<<"Not jolly"<<endl;
		
	}
	return 0;
}