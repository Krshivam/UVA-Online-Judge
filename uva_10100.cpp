#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[])
{
	string s1,s2;
	int kase=1;
	while(getline(cin,s1)){
		getline(cin,s2);
		int n= s1.length();
		int m = s2.length();
		cout<<setw(2);
		if(n==0 || m==0){
			cout<<kase<<". "<<"Blank!"<<endl;
		}
		else
{			for (int i = 0; i < n; ++i)
			{
				if(!isupper(s1[i]) && !islower(s1[i]) && !isdigit(s1[i])) s1[i]=' ';
			}
			for (int i = 0; i < m; ++i)
			{
				if(!isupper(s2[i]) && !islower(s2[i]) && !isdigit(s2[i])) s2[i]=' ';
			}
			std::vector<string> v1,v2;
			string s3,s4;
			istringstream f(s1);
			istringstream f1(s2);
			while(f>>s3) v1.pb(s3);
			while(f1>>s4) v2.pb(s4);
			//cout<<v1.size()<<" "<<v2.size();
			
			int dp[v1.size()+1][v2.size()+1];
			for (int i = 0; i <= v1.size(); ++i)
			{
				for (int j = 0; j <=v2.size(); ++j)
				{
					if(i==0 ||j==0) dp[i][j]=0;
					else if(v1[i-1]==v2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
					else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
			cout<<kase<<". Length of longest match: "<<dp[v1.size()][v2.size()]<<endl;
		}
		kase++;
	}
	return 0;
}