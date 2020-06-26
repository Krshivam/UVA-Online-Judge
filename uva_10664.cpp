#include<bits/stdc++.h>
using namespace std;

int wt[201];
int dp[201][201];

int f(string s){
	stringstream f1(s);
	int x=0;
	f1>>x;
	return x;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		
		string str;
        getline(cin,str);
        stringstream ss;
        ss<<str;
        int val;
        int sum=0;
        int cnt=0;
        while(ss>>val)
        {
        	cnt++;
            wt[cnt]=val;
            sum+=val;
        }

		//cout<<sum<<endl;
		if(sum&1){
			cout<<"NO"<<endl;
		}else{


		int x= sum/2;

		for (int i = 1; i <=x; ++i)
		{
			dp[0][i] = 0;
		}
		for (int i = 1; i <=cnt; ++i)
		{
			for (int j = 1; j <=x ; ++j)
			{
				if(wt[i]>j) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j],wt[i]+dp[i-1][j-wt[i]]);
			}
		}
		//cout<<dp[cnt][x]<<endl;
		int result = sum-2*dp[cnt][x];
		//cout<<result<<endl;
		if(result==0){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	}
	return 0;
}