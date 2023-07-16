#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=1e9+7;
int nmax,kmax;
vector<vector<int>>dp;
vector<vector<int>>prefix;
void solve(){
	int n=nmax;
	int k=kmax;
	dp[0][0]=21;
	dp[0][1]=5;
	prefix[0][0]=21;
	prefix[0][1]=26;
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=21*dp[i-1][j];
			prefix[i][j]=dp[i][j];
			if(j){
				dp[i][j]+=prefix[i-1][j-1]*5;
				prefix[i][j]+=prefix[i][j-1];
			}
			dp[i][j]%=mod;
			prefix[i][j]%=mod;
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++){
		ans+=dp[n-1][i];
		ans%=mod;
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
	vector<pair<int,int>>query;
	while(T--){
		int n;cin>>n;
		int k;cin>>k;
		kmax=max(k,kmax);
		nmax=max(n,nmax);
		query.push_back({n,k});
	}
	dp.assign(nmax+1,vector<int>(kmax+1,0));
	prefix.assign(nmax+1,vector<int>(kmax+1,0));
	// solve();
	// for(auto q:query){
	// 	cout<<prefix[q.first-1][q.second]<<nline;
	// }
	solve();
	return 0;
}