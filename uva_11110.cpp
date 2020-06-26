#include<bits/stdc++.h>
using namespace std;
int grid[101][101];
int n;
int ans=0;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

void dfs(int x,int y,int nm){
	grid[x][y] = 0;
	ans++;
	for (int i = 0; i <4 ; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dx1<n && dy1>=0 && dy1<n && grid[dx1][dy1]==nm){
			dfs(dx1,dy1,nm);
		}
	}
}

int main(int argc, char const *argv[])
{
	while((cin>>n)&&n){
		//int x,y;
		int flg=0;
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				grid[i][j] = n;
			}
		}
		string aux;
        getline(cin,aux);
		for(int i=1;i<n;i++) 
        {
            string s;
            getline(cin,s);
            //cout<<n<<endl;
            stringstream is(s);
            int x, y;
            while(is>>x>>y)
            {
                grid[x-1][y-1] = i;
            }
        }
		
		int x1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ans=0;
				
				if(grid[i][j]){
					x1=grid[i][j];
					dfs(i,j,grid[i][j]);
					//cout<<grid[i][j]<<" "<<ans<<endl;
					if(ans!=n) flg=1;
				}
			}
		}
		if(flg) cout<<"wrong"<<endl;
		else cout<<"good"<<endl;
	}
	return 0;
}