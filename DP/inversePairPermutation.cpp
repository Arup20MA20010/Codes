#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=1e9+7;
int dp[1001][1001];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;++){
			for(int l=0;l<=min(k,n-1);l++){
				dp[i][j]+=dp[i-1][j-l];
			}
		}
	}
	cout<<dp[n][k]<<nline;
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