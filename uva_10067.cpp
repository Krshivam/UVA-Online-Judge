#include<bits/stdc++.h>
using namespace std;
int visited[10005],dist[10005];

int convert(int child[]){
	int num = 0;
	num += child[0]*1000+child[1]*100+child[2]*10+child[3];
	return num;
}

void bfs(int strt,int end){
	visited[strt] = 1;
	dist[strt] = 0;
	queue<int>q;
	q.push(strt);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		if(f==end){
			cout<<dist[f]<<endl;
			return ;
		}
		int child[4];
		child[0] = f/1000;
		child[1] = (f%1000)/100;
		child[2] = (f%100)/10;
		child[3] = f%10;
		//cout<<child[0]<<child[1]<<child[2]<<child[3]<<endl;
		for (int i = 0; i < 4; ++i)
		{
			child[i]+=1;
			child[i] %= 10;
			int num = convert(child);
			if(num>=0 &&  num<=9999 && !visited[num]){
				dist[num] = dist[f]+1;
				q.push(num);
				visited[num]  =1;
				child[0] = f/1000;
				child[1] = (f%1000)/100;
				child[2] = (f%100)/10;
				child[3] = f%10;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			child[i]-=1;
			if(child[i]==-1) child[i] = 9;
			int num = convert(child);
			if(num>=0 &&  num<=9999 && !visited[num]){
				dist[num] = dist[f]+1;
				q.push(num);
				visited[num]=1;
				child[0] = f/1000;
				child[1] = (f/100)%10;
				child[2] = (f/10)%10;
				child[3] = f%10;
			}
		}
			
	}
	cout<<-1<<endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		//m.clear();
		int x1,x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		int strt = 1000*x1+100*x2+10*x3+x4;
		cin>>x1>>x2>>x3>>x4;
		int end = 1000*x1+100*x2+10*x3+x4;
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>x1>>x2>>x3>>x4;
			visited[1000*x1+100*x2+10*x3+x4]=1;
		}
		bfs(strt,end);
	}
	return 0;
}