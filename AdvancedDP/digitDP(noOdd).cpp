#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[32][2][2];
string L;string R;
int n;
int rec(int level,int tightLo,int tightHi){
	if(level==n-1){
		int count=0;
		//base case is easy not implementing
	}//
	if(dp[level][tightHi][tightLo]!=-1){
		return dp[level][tightHi][tightLo];
	}
	int ans=0;
	int lo=L[level]-'0';
	int hi=L[level]-'0';
	if(tightHi&tightLo){
		if(hi==lo){
			ans=rec(level+1,tightLo,tightHi);
		}else{
			ans=rec(level+1,tightLo,0)+(hi-lo-1)*rec(level+1,0,0)+rec(level+1,0,rightHi);
		}
	}else if(tightHi){
		ans=hi*rec(level+1,0,0)+rec(level+1,0,tightHi);
	}else if(tightLo){
		ans=(9-lo)*rec(level+1,0,0)+rec(level+1,tightLo,0);
	}else{
		ans=10*rec(level+1,0,0);
	}
	return dp[level][tightHi][tightLo]=ans;
}
void solve(){

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