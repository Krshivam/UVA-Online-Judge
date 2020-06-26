#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll unsigned long long int


void fact(std::vector<int>&v,ll n){
	ll cnt=1;
	while(n!=0){
		v.pb(n%cnt);
		n/=cnt;
		cnt++;
	}
	//reverse(v.begin(), v.end());
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		std::vector<int> ord;
		string s;
		cin>>s;
		ll n;
		cin>>n;
		fact(ord,n);
		sort(s.begin(),s.end());
		//reverse(ord.begin(),ord.end());
        int j=s.size()-ord.size();
        for(int i=0;i<j;i++)
            ord.push_back(0);
        reverse(ord.begin(),ord.end());
        for(int i=0;i<ord.size();i++){
            cout<<s[ord[i]];
            s.erase(ord[i],1);
        }
        cout<<endl;
	}
	return 0;
}