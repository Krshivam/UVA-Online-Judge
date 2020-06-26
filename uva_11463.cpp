#include<bits/stdc++.h>
using namespace std;
#define pb push_back

std::vector<std::vector<int> >adjMatrix;
int n;

void floydWarshall(){
	for (int i = 0; i < n; ++i)
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
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		cin>>n;
		adjMatrix.clear();
		adjMatrix.resize(n,std::vector<int> (n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				adjMatrix[i][j] = 1e9;
				if(i==j) adjMatrix[i][j] = 0;
			}
		}
		int m;
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			
				int a,b;
				cin>>a>>b;
				adjMatrix[a][b] = 1;
				adjMatrix[b][a] = 1;
		}
		int a,b;
		cin>>a>>b;
		floydWarshall();
		int tme=0;
		for (int i = 0; i < n; ++i)
		{
			if(adjMatrix[a][i]!=1e9 && adjMatrix[i][b]!=1e9){
				tme = max(tme,adjMatrix[a][i]+adjMatrix[i][b]);
			}
		}
		cout<<"Case "<<kase<<": "<<tme<<endl;
		kase++;
	}
	return 0;
}