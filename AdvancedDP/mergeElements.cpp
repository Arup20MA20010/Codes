#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[51][51][51];
int done[51][51];
int A[51];
int x,y,z;
int n;
int rec(int l,int r,int c){
	if(l==r){
		if(c==A[l])return 0;
		return 1e10;
	}
	if(done[l][r])return dp[l][r][c];
	int ans=1e18;
	for(int i=0;i<=50;i++)dp[l][r][i]=1e18;
	for(int k=l;k<r;k++){
		for(int a=0;a<=50;a++){
			for(int b=0;b<=50;b++){
				dp[l][r][(a*x+b*y+z)%50]=min(dp[l][r][(a*x+b*y+z)%50],rec(l,k,a)+rec(k+1,r,b)+a*b);
			}
		}
	}
	done[l][r]=1;
	return dp[l][r][c];
}
void solve(){
	cin>>n>>x>>y>>z;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int ans=1e18;
	for(int c=0;c<50;c++){
		ans=min(ans,rec(0,n-1,c));
	}
	cout<<ans<<nline;
	// for(int i=0;i<=n-1;i++){
	// 	for(int j=0;j<=n-1;j++){
	// 		cout<<val[i][j]<<" ";
	// 	}
	// 	cout<<nline;
	// }
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