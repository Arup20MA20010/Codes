#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int rec(int level,int i,vector<vector<int>>dp,vector<int>A,int n){
	if(level>n||n-level+i<0||i>=n){
		//base case
		return 0;
	}
	//cache check
	if(dp[level][i]!=-1)return dp[level][i];
	//recursive case
	int ans=max(rec(level+2,i+1,dp,A,n)+A[n-level+i],rec(level+2,i+2,dp,A,n)+A[i]);
	return dp[level][i]=ans;
}
void solve(){
	int n;cin>>n;
	vector<int>A(n,0);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	int ans=rec(1,0,dp,A,n);
	for(int i=1;i<=n;i++){
		for(int )
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}