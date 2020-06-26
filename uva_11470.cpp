#include<bits/stdc++.h>
using namespace std;

int n,grid[11][11];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int sum=0;
/*5
5 3 2 7 9
1 7 4 2 4
5 3 2 4 6
1 3 4 5 1
1 4 5 6 3
1
1
0*/

void dfs(int x,int y,int side){
	sum+=grid[x][y];
	grid[x][y] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && dy1<n  && grid[dx1][dy1] && (dx1==side || dy1==side)){
			dfs(dx1,dy1,side);
		}
	}
}


int main(int argc, char const *argv[])
{
	int kase=1;
	while((cin>>n)&&n){
		memset(grid,0,sizeof(grid));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>grid[i][j];
			}
		}
		cout<<"Case "<<kase<<":";
		for (int i = 0; i < (int)ceil(n*1.0/2); ++i)
		{
			sum=0;
			if(grid[i][i]){
				//cout<<
				dfs(i,i,i);
				if(grid[n-i-1][n-i-1]){
					dfs(n-i-1,n-i-1,n-i-1);
				}
				
				cout<<" "<<sum;
			}

		}
		cout<<endl;
		kase++;
	}
	return 0;
}