#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct hasher{
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
	string s;cin>>s;
	int n=s.length();
	hasher h1;
	h1.init(s,31,1e9+7);
	hasher h2;
	h2.init(s,37,1e9+9);
	string c;cin>>c;
	vector<int>prefix(n,0);
	for(int i=0;i<n;i++){
		prefix[i]=1-(c[s[i]-'a']-'0');
		if(i)
			prefix[i]+=prefix[i-1];
	}
	set<pair<int,int>>st;
	int k;cin>>k;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int countK=prefix[j]-(i>0?prefix[i-1]:0);
			if(countK<=k){
				st.insert({h1.getHashVal(i,j),h2.getHashVal(i,j)});
			}
		}
	}
	cout<<st.size()<<nline;
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