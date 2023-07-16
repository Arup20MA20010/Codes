#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int rollingHash(string s,int p,int m){
	int ans=(s[0]-'a'+1);
	for(int i=1;i<s.length();i++){
		ans=(ans*p+(s[i]-'a'+1))%m;
	}
	return ans;
}
struct hasher{
	int sz,p,mod;
	vector<int>fHash;
	vector<int>pk;
	void init(string s,int p,int mod){
		this->p=p;
		this->mod=mod;
		sz=s.length();
		fHash.resize(sz);
		pk.resize(sz);
		fHash[0]=(s[0]-'a'+1);
		pk[0]=1;
		for(int i=1;i<sz;i++){
			fHash[i]=(fHash[i-1]*p+(s[i]-'a'+1))%mod;
			pk[i]=p*pk[i-1];
		}
	}
	int getHashVal(int l,int r){
		if(l==0)return fHash[r];
		return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod+mod)%mod;
	}
};
void solve(){

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