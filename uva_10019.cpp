#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x = n;
		int cnt1=0;
		int cnt2=0;
		while(x){
			cnt1+= (x&1);
			x = x>>1;
		}
		x = n;
		int i=0;
		int ans=0;
		while(x){
			ans+= pow(16,i)*(x%10);
			x/=10;
			i++;
		}
		while(ans){
			cnt2+= (ans&1);
			ans = ans>>1;
		}
		cout<<cnt1<<" "<<cnt2<<endl;
	}
	return 0;
}