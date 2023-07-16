#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=998244353;
int rem(int a){
	return a%mod;
}
int mulMod(int a,int b){
	return rem(rem(a)*rem(b));
}
int binPow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=mulMod(ans,a);
		}
		a=mulMod(a,a);
		b>>=1;
	}
	return ans;
}
int inverse(int a){
	return binPow(a,mod-2);
}
int divideMod(int a,int b){
	return mulMod(a,inverse(b));
}
int addMod(int a,int b){
	return rem(rem(a)+rem(b));
}
int factorial[5001];
int ifactorial[5001];
void fillFactorial(){
	factorial[1]=1;
	factorial[0]=1;
	for(int i=2;i<=5000;i++){
		factorial[i]=mulMod(factorial[i-1],i);
	}
	ifactorial[0]=1;
	for(int i=1;i<=5000;i++){
		ifactorial[i]=mulMod(ifactorial[i-1],inverse(i));
	}
}
int ncr(int n,int r){
	return mulMod(factorial[n],mulMod(ifactorial[n-r],ifactorial[r]));
}
//dp(i,j) by taking first i letters the no. of permutations that can be formed of length j.
int freq[26];
int dp[26][5050];
void solve(){
	string s;cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		freq[s[i]-'a']++;
	}
	for(int j=0;j<=min(freq[0],n);j++){
		dp[0][j]=1;
	}
	for(int i=1;i<26;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=min(freq[i],j);k++){
				dp[i][j]+=mulMod(dp[i-1][j-k],ncr(j,k));
				dp[i][j]%=mod;
			}
		}
	}
	// cout<<ncr(5,2)<<nline;
	int ans=0;
	for(int j=1;j<=n;j++){
		ans=addMod(ans,dp[25][j]);
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
	fillFactorial();
	solve();
	return 0;
}