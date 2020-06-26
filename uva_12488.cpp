#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		int arr[25],arr1[25];
		int d;
		for (int i = 0; i < ; ++i)
		{
			cin>>d;
			arr[d] = i;
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>arr1[i];
		}
		int cnt=0;
		for (int i = 0; i < n-1; ++i)
		{
			int j=i;
			while(i!=arr[arr1[j]]){
				cnt++;
				swap(arr1[j],arr1[j+1]);
				j++;
			}
		}
		//cout<<cnt
	}
	return 0;
}