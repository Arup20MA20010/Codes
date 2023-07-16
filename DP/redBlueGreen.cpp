#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int ans(string s,string pattern,int k){
	int n=s.length();
	vector<int>dp(n,0);
	//calculate dp[k],dp[k+1],dp[k-1]
	//dp[k-1]
	for(int i=0;i<k;i++){
		if(s[i]!=pattern[i%3])dp[k-1]++;
		// cout<<s[i]<<" "<<pattern[i%3]<<nline;
	}
	//dp[k]
	if(k==n)return dp[k-1];
	for(int i=1;i<=k;i++){
		if(s[i]!=pattern[(i-1)%3])dp[k]++;
	}
	if(k+1==n)return min(dp[k],dp[k-1]);
	//dp[k+1]
	for(int i=2;i<=k+1;i++){
		if(s[i]!=pattern[(i-2)%3])dp[k+1]++;
	}
	for(int i=k+2;i<n;i++){
		dp[i]=dp[i-3]+(s[i]!=pattern[(k+2)%3])+(s[i-1]!=pattern[(k+1)%3])+(s[i-2]!=pattern[k%3])-(s[i-k]!=pattern[2])-(s[i-k-1]!=pattern[1])-(s[i-k-2]!=pattern[0]);

	}
	int mini=1e18;
	// cout<<pattern<<nline;
	for(int i=k-1;i<n;i++){
		// cout<<dp[i]<<" ";
		mini=min(mini,dp[i]);
	}
	// cout<<nline;
	return mini;
}
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	// ans(s,"RGB",k);
	// cout<<nline;
	// cout<<"after"<<nline;
	cout<<min(ans(s,"RGB",k),min(ans(s,"GBR",k),ans(s,"BRG",k)))<<nline;
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