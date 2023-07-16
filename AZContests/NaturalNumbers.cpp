#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=1e9+7;
void solve(){
	int n,k;cin>>n>>k;
	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
	for(int i=1;i<=n;i++){
		dp[i][1]=1;
		dp[1][i]=1;
		dp[0][i]=1;
		
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=min(i,k);j++){
			
		}
	}
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