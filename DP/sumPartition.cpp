#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<pair<int,int>>queries;
int maxN=0,maxK=0;
const int mod=1e9+7;
int dp[5001][5001];
int prefix[5001][5001];
void solve(){
	for(int i=1;i<=maxN;i++){
		dp[i][i]=1;
		dp[i][1]=1;
		prefix[i][1]=1;
	}
	for(int j=1;j<=maxN;j++){
		prefix[1][j]=dp[1][j]+prefix[1][j-1];
		prefix[2][j]=dp[2][j]+prefix[2][j-1];
		prefix[2][j]%=mod;
		prefix[1][j]%=mod;
	}
	for(int i=2;i<=maxN;i++){
		for(int j=1;j<=maxK;j++){
			if(i>j)
				dp[i][j]=prefix[i-j][j];
			prefix[i][j]=dp[i][j]+prefix[i][j-1];
			prefix[i][j]%=mod;
		}
	}
	for(auto q:queries){
		if(q.first<q.second)
			cout<<0<<nline;
		else
			cout<<dp[q.first][q.second]<<nline;
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
	while(T--){
		int n,k;cin>>n>>k;
		queries.push_back({n,k});
		maxN=max(maxN,n);
		maxK=max(maxK,k);
	}
	solve();
	return 0;
}