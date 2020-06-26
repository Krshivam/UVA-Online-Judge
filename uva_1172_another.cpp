
#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef pair<int,int> ii;

string os[1010][2];
int oid[1010][2];
int cost[1010][2];
ii dp[1010];

int main(){
  int T,n,m;
  string tmp;
  ios::sync_with_stdio(false);
  cin >> T;
  while( T-- ){
    int idx = 0;
    map<string,int> mp;
    cin >> n;
    rep(i,n) {
      cin >> tmp >> os[i][0] >> cost[i][0];
      if( !mp.count(os[i][0]) ) mp[os[i][0]] = idx++;
      oid[i][0] = mp[os[i][0]];
    }
    cin >> m;
    rep(i,m) {
      cin >> tmp >> os[i][1] >> cost[i][1];
      if( !mp.count(os[i][1]) ) mp[os[i][1]] = idx++;
      oid[i][1] = mp[os[i][1]];
    }
    int V = max(n,m);
    rep(i,V) dp[i] = ii(0,0);

    rep(i,n){
      for(int j=m-1;j>=0;j--){
        if( oid[i][0] != oid[j][1] ) continue;
        if( dp[j].first < ((j-1>=0)?dp[j-1].first:0) + cost[i][0] + cost[j][1] ) {
          dp[j].first = ((j-1>=0)?dp[j-1].first:0) + cost[i][0] + cost[j][1];
          dp[j].second = ((j-1>=0)?dp[j-1].second:0) + 1;
        } else if( dp[j].first == ((j-1>=0)?dp[j-1].first:0) + cost[i][0] + cost[j][1] ) {
          int num = ((j-1>=0)?dp[j-1].second:0) + 1;
          dp[j].second = min(dp[j].second,num);
        }
      }
      REP(j,1,m){
        if( dp[j].first < dp[j-1].first ) dp[j] = dp[j-1];
        else if( dp[j].first == dp[j-1].first && dp[j].second > dp[j-1].second ) dp[j] = dp[j-1];
      }
    }
    cout << dp[m-1].first << " " << dp[m-1].second << endl;
  }
  return 0;
}