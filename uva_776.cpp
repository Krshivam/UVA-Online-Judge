#include<bits/stdc++.h>
using namespace std;

char grid[120][120];
bool visited[120][120];
int mygrid[120][120];
int dx[] = {-1,0,1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};

int m=0;
int n=0;
void dfs(int x,int y,int nm,char init_chr){
	visited[x][y] = 1;
	mygrid[x][y] = nm;
	//cout<<"hello"<<endl;
	for (int i = 0; i < 8; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dx1<n && dy1>=0 && dy1<m && grid[dx1][dy1]==init_chr && !visited[dx1][dy1]){
			dfs(dx1,dy1,nm,init_chr);
		}
	}
}


int main(int argc, char const *argv[])
{
	char s[1024];
	int flg=0;
	while(true){
		n = 0,m;
		memset(visited,0,sizeof(visited));
		memset(mygrid,0,sizeof(mygrid));
		while(gets(s)){
			if(s[0]=='%') {break;}

			m=0;
			for (int i = 0; s[i]; ++i)
			{
				if(s[i]!=' '){
					grid[n][m++] = s[i];
				}
			}
			n++;
		}
		//cout<<n<<" "<<m;
		int cnt=1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(!visited[i][j]){
					dfs(i,j,cnt,grid[i][j]);
					cnt++;
				}
			}
		}
		
		int align[120]={};
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int tmp = mygrid[j][i];
				int cnt = 0;
				while(tmp){
					tmp /= 10;
					cnt++;
				}
				if(align[i]<cnt){
					align[i] = cnt;
				}
			}
		}
		char format[100] = "%?d";
		for (int i = 0; i < n; ++i,puts(""))
		{
			for (int j = 0; j < m; ++j)
			{
				format[1] = align[j] + '0';
				if(j) putchar(' ');
				printf(format, mygrid[i][j]);
			}
			//cout<<endl;
		}
		cout<<'%'<<endl;
		if(s[0] != '%')
            break;
	}
	return 0;
}