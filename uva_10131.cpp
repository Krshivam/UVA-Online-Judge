#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
pii arr[1001];
int a,b;
int n=0;
std::map<pii, int> m;
bool compare(pii x,pii y){
	if(x.first==y.first) return x.second<y.second;
	return x.first<y.first;
}
int parent[1001];

std::vector<int> v;
void lis(){
	int arr1[1001];
	for (int i = 0; i < n; ++i)
	{
		arr1[i] = 1;
	}
	int parent[1001];
	for (int i = 0; i <n ; ++i)
	{
		parent[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr1[j]+1>arr1[i] && arr[j].second>arr[i].second && arr[j].first<arr[i].first){
				arr1[i] = arr1[j]+1;
				parent[i] = j;
			}
			
		}
	}
	int mx = 0;
	int idx;
	for (int i = 0; i < n; ++i)
	{
		if(mx<arr1[i]){
			idx=i;
			mx = arr1[i];
		}
	}
	while(idx!=parent[idx]){
		v.pb(m[arr[idx]]+1);
		idx = parent[idx];
	}
	v.pb(m[arr[idx]]+1);
	cout<<mx<<endl;
	for (int i = v.size()-1; i>=0; i--)
	{
		cout<<v[i]<<endl;
	}
}


int main(int argc, char const *argv[])
{
	
	while(cin>>a>>b){
		arr[n].first = a;
		arr[n].second = b;
		m[mp(a,b)] = n;
		n++;
	}
	sort(arr,arr+n);
	//cout<<n<<endl;
	lis();
	return 0;
}