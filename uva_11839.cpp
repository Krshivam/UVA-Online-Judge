#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	while((cin>>n)&&n){
		for (int j = 0; j < n; ++j)
		{
			int id;
			int cnt=0;
			int d;
			for (int i = 0; i < 5; ++i)
			{
				cin>>d;
				if(d<=127) id = i,cnt++;
			}
			if(cnt==1){
				char x = id+65;
				cout<<x<<endl;
			}
			else cout<<'*'<<endl;	
		}
	}
	return 0;
}