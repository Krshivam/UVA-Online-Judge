#include<bits/stdc++.h>
using namespace std;
#define  mp make_pair
std::map<char, char>  ml,mr;
std::map<char, pair<int,int> > dist;
std::map<pair<int , int>,int >m1;

int main(int argc, char const *argv[])
{
	mr['E'] = 'S';
mr['N'] = 'E';
mr['W'] = 'N';
mr['S'] = 'W';
ml['E'] = 'N';
ml['N'] = 'W';
ml['W'] = 'S';
ml['S'] = 'E';
dist['E'] = mp(1,0);
dist['N'] = mp(0,1);
dist['W'] = mp(-1,0);
dist['S'] = mp(0,-1);
	int n,m;
	cin>>n>>m;
	int x,y;
		char d;
	while(cin>>x>>y>>d)
	{
		
		string s;
		//cin>>x>>y>>d;
		cin>>s;
		int t=0;
		for (int j = 0; j <s.length(); ++j)
		{
			if(s[j]=='L') d = ml[d];
			else if(s[j]=='R') d = mr[d];
			else {
				x += dist[d].first;
			    y += dist[d].second;
			}
			if((x>n || x<0 || y<0 || y>m)&& m1[mp(x-dist[d].first,y-dist[d].second)]==0){
				t=1;
				cout<<x-dist[d].first<<" "<<y-dist[d].second<<" "<<d
				<<" LOST"<<endl;
				m1[mp(x-dist[d].first,y-dist[d].second)] = 1;
				break;
			}
			if((x>n || x<0 || y<0 || y>m)&&m1[mp(x-dist[d].first,y-dist[d].second)]==1){
				x-=dist[d].first,y-=dist[d].second;
			}
			//cout<<x<<" "<<y<<endl;
			//cout<<d<<endl;
		}
		if(!t){
			cout<<x<<" "<<y<<" "<<d<<endl;
		}
		
	}
	return 0;
}