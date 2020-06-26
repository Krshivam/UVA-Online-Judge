#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int v,v_0;
	while((cin>>v>>v_0)&&v){
		if(v%(2*v_0)!=0) cout<<0<<endl;
		else cout<<v/(2*v_0)<<endl;
	}
	return 0;
}