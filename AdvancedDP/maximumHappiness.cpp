#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[16][(1<<15)+1];
int happy[16][16];
int n;
int rec(int level,int mask){
	if(level==n)return 0;
	if(dp[level][mask]!=-1)return dp[level][mask];
	int cost1=0;int cost0=0;
	int ans=0;
	for(int i=1;i<=level;i++){
		if((mask<<(i-1))&1){
			cost1+=happy[i][level];
		}else{
			cost0+=happy[i][level];
		}
	}
	ans=max(rec(level+1,mask|(1<<level))+cost1,rec(level+1,mask)+cost2);
	return dp[level][mask]=ans;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>happy[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<nline;
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