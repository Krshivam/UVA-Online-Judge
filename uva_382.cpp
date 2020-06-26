#include<bits/stdc++.h>
using namespace std;

int f(int n){
	int ans=0;
	if(n==1 || n==2) return 0;
	//if(n==2) return 3;
	for (int i = 2; i*i <=n ; ++i)
	{
		if(n%i==0){
			ans += i;
			if(i*i!=n) ans += n/i;
		}
	}
	return ans+1;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(1){
		cin>>n;
		if(!n) break;
		//cout<<f(n)<<endl;
		if(f(n)==n) cout<<setfill(' ')<<setw(5)<<n<<"  PERFECT"<<endl;
		else if(f(n)<n) cout<<setfill(' ')<<setw(5)<<n<<"  DEFICIENT"<<endl;
		else cout<<setfill(' ')<<setw(5)<<n<<"  ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}