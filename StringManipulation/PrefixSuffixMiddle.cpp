#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
#define int long long
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
vector<int>getKMP(string s){
	int n=s.length();
	vector<int>res(n+1);
	res[0]=-1;
	int i=0,j=-1;
	while(i<n){
		while(j!=-1&&s[i]!=s[j]){
			j=res[j];
		}
		i++;
		j++;
		res[i]=j;
	}
	return res;
}
void solve(){
	int n;cin>>n;
	string s;
	cin>>s;
	vector<int>kmp=getKMP(s);
	hasher h1;
	h1.init(s,37,1e9+7);
	hasher h2;
	h2.init(s,31,1e9+9);
	int maxL=0;
	int start=0;
	// cout<<h1.getHashVal(0,1)<<nline;
	// cout<<h1.getHashVal(7,8)<<nline;
	for(int i=1;i<n;i++){
		int l=kmp[i];
		if(h1.getHashVal(0,kmp[i]-1)==h1.getHashVal(n-kmp[i],n-1)&&h2.getHashVal(0,kmp[i]-1)==h2.getHashVal(n-kmp[i],n-1)&&l>maxL){
			maxL=l;
			start=i-kmp[i];
		}
	}
	// cout<<nline;
	if(maxL==0){
		cout<<-1<<nline;
		return;
	}
	cout<<s.substr(start,maxL)<<nline;
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