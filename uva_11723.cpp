#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	int id=1;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0) break;
		int ans = (n-m)/m + ((n-m)%m!=0 && n>=m);
		if(ans>26) {
			cout<<"Case "<<id<<": impossible"<<endl;
		}
		else cout<<"Case "<<id<<": "<<ans<<endl;
		id++;
	}
	return 0;
}