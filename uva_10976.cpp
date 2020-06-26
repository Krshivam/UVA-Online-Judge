#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	while(cin>>k){
		std::map<int, int> m;
		for (int i = k+1; i <=2*k; ++i)
		{
			if(i*k%(i-k)==0) m[i] = (i*k)/(i-k);
			
		}
		cout<<m.size()<<endl;
		for (std::map<int, int>::iterator it=m.begin();it!=m.end();it++)
		{
			cout<<"1/"<<k<<" = "<<"1/"<<it->second<<" + "<<"1/"<<it->first<<endl;
		}
	}
	return 0;
}