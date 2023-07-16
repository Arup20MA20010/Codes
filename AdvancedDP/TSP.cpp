#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;int dist[16][16];
int dp[16][(1<<15)+1];//this returns the smallest path from travelling from node src to some node.
int rec(int src,int mask){
	//base case
	if(mask==((1<<n)-1)){
		return dist[src][1];
	}
	if(dp[src][mask]!=-1)return dp[src][mask];
	int ans=1e18;
	for(int i=1;i<=n;i++){
		if((mask>>(i-1))&1)continue;
		ans=min(ans,rec(i,mask|(1<<(i-1)))+dist[src][i]);
	}
	return dp[src][mask]=ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>dist[i][j];
		}
	}
	cout<<rec(1,1)<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}