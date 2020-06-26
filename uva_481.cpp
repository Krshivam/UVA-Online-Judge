#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define pb push_back
#define ll long long
ll arr[MAX];
ll I[MAX];
ll inf = 2000000000;

int main(int argc, char const *argv[])
{
	int n=0;
	ll num;
	while(cin>>num){
		arr[n] = num;
		n++;
	}
	I[0] = -inf;
	for (int i = 1; i < n+1; ++i)
	{
		I[i] = inf;
	}
	int lisLength=0;
	for (int i = 0; i < n; ++i)
	{
		int low,high,mid;
		high = lisLength;
		while(low<=high){
			mid = (low+high)/2;
			if(I[mid]<arr[i]){
				low=mid+1;
			}
			else high = mid-1;
		}
		I[low] = arr[i];
		if(lisLength<low){
			lisLength = low;
		}
	}
	cout<<lisLength<<endl;
	cout<<'-'<<endl;
	for (int i = 1; i < n; ++i)
	{
		if(I[i]==inf) break;
		else cout<<I[i]<<endl;
	}
	return 0;
}