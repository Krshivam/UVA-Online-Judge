#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int visited[1000][1000];
int h,w;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

void dfs(int x,int y,char clr){
	visited[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int dx1 = x+dx[i];
		int dy1 = y+dy[i];
		if(dx1>=0 && dy1>=0 && dx1<h && dy1<w && !visited[dx1][dy1] && grid[dx1][dy1]==clr){
			dfs(dx1,dy1,clr);
		}
	}
}

bool compare(pair<char,int>a,pair<char,int>b){
	if(a.second==b.second) return a.first<b.first;
	return a.second>b.second;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		
		cin>>h>>w;
		std::map<char, int> m;
		pair<char,int>arr[1000];
		memset(visited,0,sizeof(visited));
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j< w; ++j)
			{
				cin>>grid[i][j];
			}
		}
		int k=0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if(!visited[i][j]){
					dfs(i,j,grid[i][j]);
					m[grid[i][j]] += 1;
					//cout<<grid[i][j]<<" "<<m[grid[i][j]]<<endl;
				}
			}
		}
		std::map<char, int>::iterator it;
		for (it=m.begin();it!=m.end();it++)
		{
			arr[k] = make_pair(it->first,it->second);
			k++;
		}
		//cout<<k;
		sort(arr,arr+k,compare);
		cout<<"World #"<<kase<<endl;
		for (int i = 0; i < k; ++i)
		{
			cout<<arr[i].first<<": "<<arr[i].second<<endl;
		}
		kase++;
	}
	return 0;
}