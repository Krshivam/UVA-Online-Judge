#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double v,v_0;
	while((cin>>v>>v_0)&&v){
		double mx,tmp;
		mx = 0.0;
		int idx;
		int flag=1;
		for(int i=1;v/i - v_0>0;i++){
			tmp = v*i - v_0*i*i;
			if(tmp==mx){
				flag=0;
				break;
			}
			else if(tmp>mx){
				mx=tmp;
				idx = i;
			}
		}
		if(flag==0 || mx==0) cout<<0<<endl;
		else cout<<idx<<endl;
	}
	return 0;
}