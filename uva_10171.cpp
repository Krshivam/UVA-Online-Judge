#include<bits/stdc++.h>
using namespace std;

std::vector<std::vector<int> >adjMatrixY,adjMatrixM;
std::map<char, int>decode;
std::map<int, char>code;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
	int cnt=0;
	adjMatrixM.clear();
	adjMatrixY.clear();
	adjMatrixM.resize(1000,std::vector<int>(1000));
	adjMatrixY.resize(1000,std::vector<int>(1000));
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			adjMatrixM[i][j] = 1e9;
			adjMatrixY[i][j] = 1e9;
			if(i==j) adjMatrixM[i][j] = 0,adjMatrixY[i][j]=0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		char s;
		cin>>s;
		if(s=='Y'){
			cin>>s;
			char x,y;
			int d;
			cin>>x>>y>>d;
			if(!decode.count(x)) decode[x] = cnt,code[cnt]=x, cnt++;
			if(!decode.count(y)) decode[y] = cnt,code[cnt]=y,cnt++;
			adjMatrixY[decode[x]][decode[y]] = d;
			if(s=='B') adjMatrixY[decode[y]][decode[x]] = d;
		}
		else {
			cin>>s;
			char x,y;
			int d;
			cin>>x>>y>>d;
			if(!decode.count(x)) decode[x] = cnt,code[cnt]=x, cnt++;
			if(!decode.count(y)) decode[y] = cnt,code[cnt]=y, cnt++;
			adjMatrixM[decode[x]][decode[y]] = d;
			if(s=='B') adjMatrixM[decode[y]][decode[x]] = d;
		}

	}
	
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			for (int k = 0; k < cnt; ++k)
			{
				adjMatrixM[j][k] = min(adjMatrixM[j][k],adjMatrixM[j][i]+adjMatrixM[i][k]);
				adjMatrixY[j][k] = min(adjMatrixY[j][k],adjMatrixY[j][i]+adjMatrixY[i][k]);
			}
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			cout<<adjMatrixM[i][j]<<" ";
		}
		cout<<endl;
	}
	int cost=1e9;
	char ans;
	char src,dest;
	cin>>src>>dest;
	int x = decode[src];
	int y = decode[dest];
	//cout<<cnt<<endl;
	for (int i = 0; i < cnt; ++i)
	{
			if(adjMatrixY[src][i]+adjMatrixM[dest][i]<cost){
				cost = adjMatrixY[src][i]+adjMatrixM[dest][i];
				ans = code[i];
			}
	}
	cout<<cost<<" "<<ans<<endl;
}
	return 0;
}