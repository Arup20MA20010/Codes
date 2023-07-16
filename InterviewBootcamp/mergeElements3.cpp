#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[31][31][31];
int arr[31];
int k;int n;
int rec(int l,int r,int d){
	if(l==r){
		if(d==1)return 0;
		return 1e18;
	}
	if(dp[l][r][d]!=-1)return dp[l][r][d];
	int ans=1e18;
	if(d==1){
		int sum=0;
		for(int i=l;i<=r;i++){
			sum+=arr[i];
		}
		dp[l][r][1]=rec(l,r,k)+sum;
		return dp[l][r][1];
	}
	for(int t=l;t<r;t++){
		ans=min(ans,rec(l,t,1)+rec(t+1,r,d-1));
	}
	return dp[l][r][d]=ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=rec(0,n-1,1);
	cout<<(ans<1e18?ans:-1)<<nline;
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