#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int id=1;
	double d,v,u;
	while(t--){
		
		cin>>d>>v>>u;
		if(u<v || u==v || v==0){
			cout<<"Case "<<id<<": can't determine"<<endl;
		
		}
		else{
			double t1 = d*1.0/u;
		double t2 = d*1.0/(sqrt(u*u*1.0-v*v*1.0));
		t2 = abs(t2-t1);
		cout<<"Case "<<id<<": ";
		printf("%.3f\n",t2);
		}
		
		
		id++;
	}
	return 0;
}