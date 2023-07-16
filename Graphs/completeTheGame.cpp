#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[100100];
vector<vector<int>>g;
int n;
const int mod=1e9+7;
int numPath(int level){
	if(level==n)return 1;
	if(g[level].empty())return 0;
	if(dp[level]!=-1)return dp[level];
	int ans=0;
	for(auto nbrs:g[level]){
		ans+=(numPath(nbrs)%mod);
		ans%=mod;
	}
	return dp[level]=ans;
}
void solve(){
	cin>>n;int m;cin>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
	}
	memset(dp,-1,sizeof(dp));
	cout<<numPath(1)<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}