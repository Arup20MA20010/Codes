#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct Hasher{
	int sz,p,mod;
	vector<int>fHash;
	vector<int>pk;
	void init(string s,int p,int mod){
		sz=s.length();
		this->p=p;
		this->mod=mod;
		fHash.resize(sz);
		pk.resize(sz);
		fHash[0]=(s[0]-'a'+1);
		pk[0]=1;
		for(int i=1;i<s.length();i++){
			fHash[i]=(fHash[i-1]*p+(s[i]-'a'+1))%mod;
			pk[i]=(pk[i-1]*p)%mod;
		}
	}
	int getHashVal(int l,int r){
		if(l==0)return fHash[r];
		return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod+mod)%mod;
	}
};
void solve(){
	string s,t;cin>>s>>t;
	Hasher h1;
	Hasher h2;
	h1.init(s,31,999999929);
	h2.init(t,31,999999929);
	int hi=min(s.length(),t.length());
	int lo=0;
	int n=s.length();
	int m=t.length();
	int ans=0;
	while(hi>=lo){
		int mid=(hi+lo)/2;
		set<int>st;
		for(int i=0;i<=n-mid;i++){
			st.insert(h1.getHashVal(i,i+mid-1));
		}
		bool Ok=0;
		for(int i=0;i<=m-mid;i++){
			if(st.find(h2.getHashVal(i,i+mid-1))!=st.end()){
				Ok=1;
				break;
			}
		}
		if(Ok){
			ans=mid;
			lo=mid+1;
		}else{
			hi=mid-1;
		}
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
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}