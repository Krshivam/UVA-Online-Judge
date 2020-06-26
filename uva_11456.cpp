#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n],arr1[n],arr2[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			arr1[i] = 1;
			arr2[i] = 1;
		}
		for (int i = n-1; i>=0; i--)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(arr[j]>arr[i]){
					arr1[i] = max(arr1[i],1+arr1[j]);
				}
				if(arr[j]<arr[i]){
					arr2[i] = max(arr2[i],1+arr2[j]);
				}
			}
		}
		int mx=0;
		for (int i = 0; i < n; ++i)
		{
			mx = max(mx,arr2[i]+arr1[i]-1);
		}
		cout<<mx<<endl;
	}
	return 0;
}