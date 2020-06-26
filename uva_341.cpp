#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> >adjMatrix,parent;
int n;

void floydWarshall(){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(adjMatrix[j][k]>adjMatrix[j][i]+adjMatrix[i][k]){
					adjMatrix[j][k]=adjMatrix[j][i]+adjMatrix[i][k];
					parent[j][k] = parent[i][k];
				}
			}
		}
	}
}

void printPath(int i,int j){
	if(i!=j) printPath(i,parent[i][j]);
	cout<<" "<<j+1;
}

int main(int argc, char const *argv[])
{
	
	int kase=1;
	while((cin>>n)&&n){
		adjMatrix.clear();
		parent.clear();
		parent.resize(n,std::vector<int> (n));
		adjMatrix.resize(n,std::vector<int> (n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <n ; ++j)
			{
				
				parent[i][j] = i;
				adjMatrix[i][j]=1e9;
				if(i==j){
					adjMatrix[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin>>t;
			for (int j = 0; j < t; ++j)
			{
				int a,b;
				cin>>a>>b;
				adjMatrix[i][a-1] = b;
				//parent[i][a-1] = i;
				//adjMatrix[a-1][i] = b;
			}
		}
		floydWarshall();
		int a,b;
		cin>>a>>b;
		a--,b--;
		cout<<"Case "<<kase<<": Path =";
		printPath(a,b);
		cout<<"; "<<adjMatrix[a][b]<<" second delay"<<endl;
		kase++;
	}
	return 0;
}