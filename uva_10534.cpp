#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		int arr[n],arr1[n],arr2[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			arr1[i] = 1;
			arr2[i] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <i ; ++j)
			{
				if(arr[i]>arr[j] && arr1[i]<arr1[j]+1){
					arr1[i]=arr1[j]+1;
				}
			}
		}
		for (int i = n-1; i>=0 ; i--)
		{
			for (int j = n-1; j>i ; j--)
			{
				if(arr[i]>arr[j] && arr2[i]<arr2[j]+1){
					arr2[i]=arr2[j]+1;
				}
			}
		}
		int sm=0;

		for (int i = 0; i < n; ++i)
		{
			sm = max(sm,min(arr2[i],arr1[i]));
		}
		cout<<sm*2-1<<endl;
	}
	return 0;
}