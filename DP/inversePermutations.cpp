#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[1001][1001];
const int mod=1e9+7;
void solve(){
	int T;cin>>T;
	vector<pair<int,int>>query;
	int maxVal=0;
	int kmax=0;
	while(T--){
		int n;cin>>n;
		int k;cin>>k;
		maxVal=max(n,maxVal);
		kmax=max(k,kmax);
		query.push_back({n,k});
	}
	for(int i=1;i<=maxVal;i++){
		dp[i][0]=1;
		dp[i][1]=i-1;
	}
	for(int i=2;i<=maxVal;i++){
		for(int k=2;k<=kmax;k++){
			dp[i][k]=dp[i-1][k]+dp[i][k-1]-(k>=i?dp[i-1][k-i]:0);
			dp[i][k]+=mod;
			dp[i][k]%=mod;
			
		}
	}
	for(auto v:query){
		cout<<dp[v.first][v.second]<<nline;
	}
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
