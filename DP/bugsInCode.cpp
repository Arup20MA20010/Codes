#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[2][501][501];
int arr[501];
void solve(){
	int n,m,b;cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		dp[i&1][0][0]=1;
		for(int z=1;z<=b;z++){
			dp[i&1][0][z]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int y=1;y<=m;y++){
			for(int z=0;z<=b;z++){
				dp[i&1][y][z]=0;
				if(z>=arr[i]){
					dp[i&1][y][z]+=dp[i&1][y-1][z-arr[i]];
				}
				if(i>1){
					dp[i&1][y][z]+=dp[(i-1)&1][y][z];
				}
			}
		}
	}
	int ans=0;
	for(int z=0;z<=b;z++){
		ans+=dp[n&1][m][z];
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
	solve();

	return 0;
}