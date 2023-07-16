#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[22][(1<<21)+1];
int n;
int arr[22][22];
const int mod=1e9+7;
int rec(int level,int mask){
	if(level==n){
		if(mask==((1<<n)-1))return 1;
		else
			return 0;
	}
	if(dp[level][mask]!=-1)return dp[level][mask];
	//chosing for level
	int ans=0;
	for(int i=0;i<n;i++){
		if((mask>>i)&1)continue;
		if(arr[level][i]){
			ans+=rec(level+1,mask|(1<<i));
			ans%=mod;
		}
	}
	return dp[level][mask]=ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	cout<<rec(0,0)<<nline;
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