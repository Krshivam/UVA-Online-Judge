#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int grid[205][205];
int color[205][205];
char s[60];
char bin[256][5];


std::vector<set<int> > neighbours;
int h,w;
int dx[] = {-1,1,0,0};
int dy[] = {0,,0,-1,1};

void convert(char c,int row,int col){
	for (int i = 0; i < 4; ++i)
	{
		grid[row][col+i] = bin[c][i]-'0';
	}
}

void dfs(int x,int y,int num){
	color[x][y] = num;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<h && dy1<w && color[dx1][dy1]==0 && grid[x][y]==grid[dx1][dy1]){
			dfs(dx1,dy1,num);
		}
	}
}

void find_new(int x,int y){
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<h && dy1<w && color[dx1][dy1]!=1 && grid[dx1][dy1]==0){
			neighbours[color[x][y]].insert(color[dx1][dy1]);
		}
	}
}

const char* code = "WAKJSD";
char recognize(int c){
	int cnt = neighbours[c].size();
	return code[cnt];
}

int main(int argc, char const *argv[])
{
	
	strcpy(bin['0'], "0000");  
    strcpy(bin['1'], "0001");  
    strcpy(bin['2'], "0010");  
    strcpy(bin['3'], "0011");  
    strcpy(bin['4'], "0100");  
    strcpy(bin['5'], "0101");  
    strcpy(bin['6'], "0110");  
    strcpy(bin['7'], "0111");  
    strcpy(bin['8'], "1000");  
    strcpy(bin['9'], "1001");  
    strcpy(bin['a'], "1010");  
    strcpy(bin['b'], "1011");  
    strcpy(bin['c'], "1100");  
    strcpy(bin['d'], "1101");  
    strcpy(bin['e'], "1110");  
    strcpy(bin['f'], "1111");
	int kase =1;
	while((cin>>h>>w)&&w){
		//trck = 0;
		memset(grid,0,sizeof(grid));
		memset(color,0,sizeof(color));
		neighbours.clear();
		
		for (int i = 0; i < h; ++i)
		{
			cin>>s;
			for (int j=0;j<w;j++)
			{
				convert(s[j],i+1,j*4+1);
			}
		}
		h+=2;
		w = w*4+2;
		std::vector<int> v1;
		int trck = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j< w; ++j)
			{
				if(!color[i][j]){
					dfs(i,j,++trck);
					//cout<<trck<<endl;
					if(grid[i][j]==1){
						v1.pb(trck);
					}
				}
			}
		}
		// /cout<<v1.size()<<endl;
		neighbours.resize(trck+1);
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if(grid[i][j]==1){
					find_new(i,j);
				}
			}
		}
		//cout<<v1.size()<<endl;
		std::vector<char> ans;
		for (int i = 0; i < v1.size(); ++i)
		{
			ans.pb(recognize(v1[i]));
		}
		sort(ans.begin(), ans.end());
		cout<<"Case "<<kase<<": ";
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i];
		}
		cout<<endl;
		kase++;
	}
	return 0;
}