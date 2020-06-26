#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int arr[10005];
std::map<pair<int,int>,int>dp;
char s[] = {'+','-'};

int find_div(int x,int i,int n,int k){
	if(i==n){
		if(x%k==0) return 1;
		return 0;
	}
	if(dp.count(mp(x,i))){
		return dp[mp(x,i)];
	}
	int ans=0;
	for (int j = 0; j < 2; ++j)
	{
		if(s[j]=='+'){
			ans |= find_div(x+arr[i],i+1,n,k);
		}
		else ans|= find_div(x-arr[i],i+1,n,k);
	}
	return dp[mp(x,i)]=ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		dp.clear();
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		if(find_div(arr[0],1,n,k)){
			cout<<"Divisible"<<endl;
		}
		else cout<<"Not divisible"<<endl;
	}
	return 0;
}