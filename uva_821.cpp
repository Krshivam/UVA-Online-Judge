#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
std::vector<std::vector<int> >adjMatrix;
int n=-1;

void floydWarshall(){
	for (int i = 0; i <n ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(adjMatrix[j][k]>adjMatrix[j][i]+adjMatrix[i][k]){
					adjMatrix[j][k] = adjMatrix[j][i]+adjMatrix[i][k];
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	
	int a,b;
	int kase=1;
	while((cin>>a>>b)&&a&&b){
		std::vector<pii> v;
		adjMatrix.clear();
		n = max(a,b);
		v.pb(mp(a,b));
		while((cin>>a>>b)&&a&&b){
			v.pb(mp(a,b));
			n=max(n,max(a,b));
		}
		adjMatrix.resize(n,std::vector<int> (n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				adjMatrix[i][j]=1e9;
				if(i==j) adjMatrix[i][j] = 0;
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			adjMatrix[v[i].first-1][v[i].second-1] = 1;
		}
		floydWarshall();
		int cnt=0;
		int sm=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(adjMatrix[i][j]<1e9 && adjMatrix[i][j]!=0){
					cnt++;
					sm+=adjMatrix[i][j];
				}
			}
		}
		double ans = sm*1.0/cnt*1.0;
		printf("Case %d: average length between pages = %0.3f clicks\n", kase,ans);
		kase++;
	}
	return 0;
}