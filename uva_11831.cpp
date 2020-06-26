#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
std::vector<std::vector<char> > grid;
std::map<char, char>  ml,mr;
std::map<char, pair<int,int> > dist;

int main(int argc, char const *argv[])
{
	int n,m,k;
	mr['E'] = 'S';
	mr['N'] = 'E';
	mr['W'] = 'N';
	mr['S'] = 'W';
	ml['E'] = 'N';
	ml['N'] = 'W';
	ml['W'] = 'S';
	ml['S'] = 'E';
	dist['E'] = mp(0,1);
	dist['N'] = mp(-1,0);
	dist['W'] = mp(0,-1);
	dist['S'] = mp(1,0);
	while((cin>>n>>m>>k)&&n){
		grid.clear();
		int cnt=0;
		grid.resize(n+2,std::vector<char>(m+2));
		int x,y;
		string s;
		char d;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='N' || grid[i][j]=='S' || grid[i][j]=='L' || grid[i][j]=='O'){
					x = i;
					y = j;
					if(grid[i][j]=='L') d='E';
					else if(grid[i][j]=='O') d = 'W';
					else d = grid[i][j];
					grid[i][j] = '.';
				}
			}
		}
		cin>>s;
		
		for (int i = 0; i < k; ++i)
		{
			if(s[i]=='D') d = mr[d];
			else if(s[i]=='E') d = ml[d];
			if(s[i]=='F'){
				if(x+dist[d].first>=0 && y+dist[d].second>=0 && grid[x+dist[d].first][y+dist[d].second]=='*'){
					cnt++;
					grid[x+dist[d].first][y+dist[d].second] = '.';
					x+= dist[d].first;
					y+= dist[d].second;
				}
				else if(x+dist[d].first>=0 && y+dist[d].second>=0 && grid[x+dist[d].first][y+dist[d].second]=='.'){
					//cnt++;
					x+= dist[d].first;
					y+= dist[d].second;
				}
			}
			//cout<<grid[4][9];
			//cout<<d<<endl; 
		}
		cout<<cnt<<endl;

	}
	return 0;
}