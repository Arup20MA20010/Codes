#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct montoneDeque{
	deque<int>dq;
	void insert(int x){
		while(!dq.empty()&&dq.back()>x){
			dq.pop_back();
		}
		dq.push_back(x);
	}
	void remove(int x){
		if(dq.front()==x)dq.pop_front();
	}
	int getMin(){
		return dq.front();
	}
};
void solve(){
	int n,m,k;cin>>n>>m>>k;
	int dp[n][2];
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int j=0;j<=m;j++){
		dp[0][j&1]=0;
		montoneDeque md;
		for(int i=1;i<n;i++){
			if(j==0){
				dp[i][j&1]=dp[i-1][j&1]+a[i-1];
			}else{
				dp[i][j&1]=dp[i-1][j&1]+a[i-1];
				md.insert(dp[i-1][(j-1)&1]+b[i-1]);
				if(i-k-1>=0)md.remove(dp[i-k-1][(j-1)&1]+b[i-k-1]);
				dp[i][j&1]=min(dp[i][j&1],md.getMin()+b[i]);
			}
		}
	}
	cout<<dp[n-1][m&1]<<nline;
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