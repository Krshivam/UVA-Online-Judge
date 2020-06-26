#include<bits/stdc++.h>
using namespace std;
int n,k;

int f(int n,int b){
	if(n==0) return 0;
	return n+f((n+b)/k,(n+b)%k);
}

int main(int argc, char const *argv[])
{
	
	
	while(scanf("%d %d", &n, &k) == 2){
		cout<<f(n,0)<<endl;
	}
	return 0;
}