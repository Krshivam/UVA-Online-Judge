#include<bits/stdc++.h>
using namespace std;

char arr[105][105];
int n;
//int ans;
//bool visited[105][105];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x,int y){
	arr[x][y] = '.';
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && dy1<n  && arr[dx1][dy1]!='.'){
			dfs(dx1,dy1);
		}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		//memset(arr,0,sizeof(arr));
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>arr[i][j];
			}
		}
		int ans=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(arr[i][j]=='x'){
					dfs(i,j);
					ans++;
				}
			}
		}
		cout<<"Case "<<kase<<": "<<ans<<endl;
		kase++;
	}
	return 0;
}