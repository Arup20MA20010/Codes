#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[(1<<20)];
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	return gcd(b,a%b);
}
int n;
int A[11];
int rec(int board,int mask){
	if(board==n+1)return 0;
	if(dp[mask]!=-1)return dp[mask];
	int ans=0;
	for(int i=0;i<2*n;i++){
		for(int j=i+1;j<2*n;j++){
			if((mask&((1<<i)|(1<<j)))==0){
				ans=max(ans,rec(board+1,mask|(1<<i)|(1<<j))+board*abs(A[i]-A[j])*gcd(A[i],A[j]));
			}
		}
	}
	return dp[mask]=ans;
}
void solve(){
	cin>>n;
	for(int i=0;i<2*n;i++)cin>>A[i];
	memset(dp,-1,sizeof(dp));
	cout<<rec(1,0)<<nline;
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