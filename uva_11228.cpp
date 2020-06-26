#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
std::vector<std::vector<pair<int,int> > > adjList;
priority_queue<pair<int,int> >pq;
std::vector<int> taken;

double find_dist(int x1,int y1,int x2,int y2){
	return 1.0*(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2));
	//if((int)d-d<0.5*(1e-9)) return (int)d+1;
	//else return (int)d;
}

void process(int u){
	taken[u] = 1;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		if(!taken[adjList[u][i].first]){
			pq.push(mp(-adjList[u][i].second,-adjList[u][i].first));
		}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int kase=1;
	while(t--){
		int n,r;
		cin>>n>>r;
		adjList.clear();
		adjList.resize(n);
		taken.clear();
		taken.resize(n,0);
		std::map<pair<int,int>, int>decode;
		for (int i = 0; i < n; ++i)
		{
			int x,y;
			cin>>x>>y;
			decode[mp(x,y)] = i;
		}
		for (std::map<pair<int,int>, int>::iterator it=decode.begin();it!=decode.end();it++)
		{
			for (std::map<pair<int,int>, int>::iterator it1=decode.begin();it1!=decode.end();it1++){
				if(it1!=it){
					adjList[decode[it->first]].pb(mp(decode[it1->first],find_dist(it->first.first,it->first.second,it1->first.first,it1->first.second)));
					adjList[decode[it1->first]].pb(mp(decode[it->first],find_dist(it->first.first,it->first.second,it1->first.first,it1->first.second)));
				}
			}
		}
		process(0);
		ll state=1;
		double roadcost=0;
		double railcost = 0;
		while(!pq.empty()){
			pair<int,int> node = pq.top();
			pq.pop();
			if(!taken[-node.second]){
				if(-node.first>r*r){
					state+=1;
					railcost+=sqrt((-node.first));
				}
				else roadcost+= sqrt((-node.first));
				process(-node.second);
			}
		}
		cout<<"Case #"<<kase<<": "<<state<<" "<<round(roadcost)<<" "<<round(railcost)<<endl;
		kase++;
	}
	return 0;
}