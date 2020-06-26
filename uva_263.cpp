#include<bits/stdc++.h>
using namespace std;

#define ll long long

string f(ll x){
	ostringstream s1;
	s1<<x;
	string s2 = s1.str();
	return s2;
}

ll f1(string s){
	stringstream f2(s);
	ll x = 0;
	f2>>x;
	return x;
}

bool compare(string x,string y){
	return x>y;
}

int main(int argc, char const *argv[])
{
	ll n;
	
	while((cin>>n)&&n){
		ll n1 = n;
		ll n2 = n;
		int cnt=0;
		ll ans=-1;
		ll ans2 =-2;
		cout<<"Original number was "<<n<<endl;
		std::map<ll, int> m;
		while(ans2 != ans){
			//ans2 = ans;
			string s1 = f(n1);
			string s2 = f(n2);
			sort(s1.begin(),s1.end(),greater<char>());
			sort(s2.begin(),s2.end());

			n1 = f1(s1);
			n2 = f1(s2);
			if(m.count(n1-n2)){
				cout<<n1<<" - "<<n2<<" = "<<n1-n2<<endl;
				cnt++;
				break;
			}
			ans = n1-n2;
			cout<<n1<<" - "<<n2<<" = "<<ans<<endl;
			n1 = ans;
			n2 = ans;
			m[ans] += 1;
			cnt++;
			//cout<<n1<<" "<<n2<<endl;
		}
		cout<<"Chain length "<<cnt<<endl<<endl;
	}
	return 0;
}