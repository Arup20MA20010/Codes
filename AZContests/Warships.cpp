#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[1001][1001];
int prefix[1001][1001];
void solve(){
	int l,m;cin>>l>>m;
	for(int i=0;i<=m;i++){
		dp[i][1]=1;
		prefix[i][1]=1;
	}
	for(int i=1;i<=m;i++){
		prefix[i][1]+=prefix[i-1][1];
		prefix[i][1]%=m;
	}
	for(int j=2;j<=l;j++){
		for(int v=0;v<m;v++){
            dp[v][j]+=1;
            if((v*v+1)%m){
                dp[v][j]+=(prefix[((v*v+1)%m)-1][j-1]);
            }
			prefix[v][j]+=dp[v][j];
			if(v)
				prefix[v][j]+=prefix[v-1][j];
			dp[v][j]%=m;
			prefix[v][j]%=m;
		}
	}
	cout<<dp[2][l]%m<<nline;
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