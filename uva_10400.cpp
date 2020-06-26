#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
char arr[] = {'/','-','*','+'};
int seq[100];
map<pair<int,int>,int >dp;

int find_min(int ans,int n,int i,int t){
	if(i==n){
		if(ans==t){
			return 0;
		}
		return 999999;
	}
	if(dp.count(mp(ans,i))) return dp[mp(ans,i)];
	//cout<<ans<<endl;
	int ans1=999999;
	for (int j = 0; j < 4; ++j)
	{
		if(arr[j]=='+' && ans+seq[i]>-32000 && ans+seq[i]<32000){
			ans1 = min(ans1,1+find_min(ans+seq[i],n,i+1,t));
		}
		else if(arr[j]=='-' && ans-seq[i]>-32000 && ans-seq[i]<32000){
			ans1 = min(ans1,1+find_min(ans-seq[i],n,i+1,t));
		}
		else if(arr[j]=='*' && ans*seq[i]>-32000 && ans*seq[i]<32000 && ans!=0){
			ans1 = min(ans1,1+find_min(ans*seq[i],n,i+1,t));
		}
		else if(arr[j]=='/' && ans%seq[i]==0 && ans!=0 && ans/seq[i]>-32000 && ans/seq[i]<32000){
			ans1 = min(ans1,1+find_min(ans/seq[i],n,i+1,t));
		}
	}
	return dp[mp(ans,i)]=ans1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		dp.clear();
		int q;
		cin>>q;
		for (int i = 0; i < q; ++i)
		{
			cin>>seq[i];
		}
		int t1;
		cin>>t1;
		cout<<find_min(0,q,0,t1)-1<<endl;
	}
	return 0;
}