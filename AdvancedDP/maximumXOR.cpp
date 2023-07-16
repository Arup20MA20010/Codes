#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int> L,R;
int dp[64][2][2][2][2];
int n;
int rec(int level,int tlo1,int thi1,int tlo2,int thi2){
	//base case
	// cout<<"hello";
	if(level==n)return 0;
	if(dp[level][tlo1][thi1][tlo2][thi2]!=-1){
		return dp[level][tlo1][thi1][tlo2][thi2];
	}
	int lo1=0,lo2=0;
	int hi1=1,hi2=1;
	if(tlo1)lo1=L[level];
	if(tlo2)lo2=L[level];
	if(thi1)hi1=R[level];
	if(thi2)hi2=R[level];
	int ans=0;
	// cout<<lo1<<lo2<<hi1<<hi2<<nline;
	for(int i=lo1;i<=hi1;i++){
		for(int j=lo2;j<=hi2;j++){
			int newTlo1=tlo1,newTlo2=tlo2;
			int newThi1=thi1,newThi2=thi2;
			if(i!=L[level])newTlo1=0;
			if(i!=R[level])newThi1=0;
			if(j!=L[level])newTlo2=0;
			if(j!=R[level])newThi2=0;
			ans=max(ans,(i^j)*(1LL<<(n-level-1))+rec(level+1,newTlo1,newThi1,newTlo2,newThi2));
			// cout<<ans<<nline;
		}
	}
	return dp[level][tlo1][thi1][tlo2][thi2]=ans;
}
void solve(){
	int l,r;
	cin>>l>>r;
	while(l){
		L.push_back(l&1);
		l>>=1;
	}
	while(r){
		R.push_back(r&1);
		r>>=1;
	}
	n=max(L.size(),R.size());
	for(int i=min(L.size(),R.size());i<n;i++){
		if(i>R.size()-1){
			R.push_back(0);
		}
		if(i>L.size()-1){
			L.push_back(0);
		}
	}
	reverse(R.begin(),R.end());
	reverse(L.begin(),L.end());
	for(int i=0;i<=n;i++){
		for(int j1=0;j1<=1;j1++){
			for(int j2=0;j2<=1;j2++){
				for(int k1=0;k1<=1;k1++){
					for(int k2=0;k2<=1;k2++){
						dp[i][j1][j2][k1][k2]=-1;
					}
				}
			}
		}
	}
	
	// cout<<nline;
	cout<<rec(0,1,1,1,1)<<nline;
	L.clear();
	R.clear();
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