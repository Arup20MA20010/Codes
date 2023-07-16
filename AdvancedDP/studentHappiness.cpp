#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n,m;
int dp[51][1027];
int happiness[50][10];
//returns the maximum hapiness from level...N given mask
int rec(int level,int mask){
	if(level==n){
		return 0;
	}
	if(dp[level][mask]!=-1)return dp[level][mask];
	//not chosing any rank
	int ans=0;
	ans=rec(level+1,mask);
	for(int j=0;j<m;j++){
		if(((mask>>j)&1)==0){
			ans=max(ans,happiness[level][j]+rec(level+1,mask|(1<<j)));
		}
	}
	return dp[level][mask]=ans;
}
void solve(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>happiness[i][j];
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