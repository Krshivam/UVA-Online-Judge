#include<bits/stdc++.h>
using namespace std;
char grid[11][16],grid_cp[11][16];
bool visited[15][25];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int sum=0;
int n = 10;
int m = 15;
void squeeze(){
	int curr_x,curr_y;
	bool flg=0;
	for (int i=0;i<m;i++)
	{
		for (int j = n-1;j>=0;j--)
		{
			if(grid[j][i]=='.'){
				curr_x=j;
				curr_y=i;
				flg=1;
			}
			else if(flg){
				grid[curr_x][curr_y] = grid[j][i];
				grid[j][i] = '.';
				if(curr_x-1>=0) flg=0;
				else curr_x--;
			}
		}
	}
	cout<<"Hello world";
	flg=0;
	for (int i = n-1; i>=0 ; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(grid[i][j]=='.') curr_x=i,curr_y=j,flg=1;
			else if(flg){
				grid[curr_x][curr_y] = grid[i][j];
				grid[i][j] = '.';
				if(curr_y+1<m) flg=0;
				else curr_y++;
			}
		}
	}
}

void dfs(int x,int y,char clr){
	//visited[x][y] = 1;
	grid[x][y]='.';
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<n && dy1<m && grid[dx1][dy1]==clr){
			sum++;
			dfs(dx1,dy1,clr);
		}
	}
}
int coord_x,coord_y;
int findmax(){
	int final_ans=0;
	for (int i=0;i<m;i++)
		{
			for (int j=n-1; j>=0 ; j--)
			{
				memset(visited,false,sizeof(visited));
				sum=0;
				if(grid[j][i]!='.'){
					dfs(j,i,grid[j][i]);
					if(sum+1>final_ans){
						final_ans = sum+1;
						coord_x = j;
						coord_y = i;
					}
				}
				
			}
		}
		//cout<<coord_x<<" "<<coord_y<<endl;
		return final_ans;
}
void my_cpy(char grid[11][16],char grid_cp[11][16]){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j<m; ++j)
		{
			grid_cp[i][j] = grid[i][j];
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 15; ++j)
			{
				cin>>grid[i][j];
			}
		}
		std::vector<int> v;
		//my_cpy(grid,grid_cp);
		//copy(&grid[0][0],&grid[0][0]+n*m,&grid_cp[0][0]);
		int ans = findmax();
		
		//copy(&grid_cp[0][0],grid_cp[0][0]+n*m,&[0][0]);
		
			
			v.push_back(ans);
			//copy(&grid_cp[0][0],&grid_cp[0][0]+n*m,&grid[0][0]);
			dfs(coord_x,coord_y,grid[coord_x][coord_y]);
			squeeze();
			for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 15; ++j)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<ans;
	}
	return 0;
}