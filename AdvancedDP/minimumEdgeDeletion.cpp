#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[16][(1<<15)+1];
int isEdge[17][17];
int n;
int rec(int level,int mask){
	if(level==n){
		return 0;
	}
	if(dp[level][mask]!=-1)return dp[level][mask];
	int ans=1e18;
	for(int i=1;i<=n;i++){
		if(!((mask>>i)&1)){
			int cost=0;
			for(int j=1;j<=n;j++){
				if((mask>>j)&1){
					cost+=isEdge[i][j];
				}
			}
			ans=min(ans,rec(level+1,mask|(1<<i))+cost);
		}
	}
	return dp[level][mask]=ans;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>isEdge[i][j];
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=(1<<n);j++){
	// 		dp[i][j]=-1;
	// 	}
	// }
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