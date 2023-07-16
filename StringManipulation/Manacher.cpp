#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct manacher{
	vector<int>p;
	void runManacher(string s){
		int n=s.length();
		p.assign(n,1);
		int l=1,r=1;
		for(int i=1;i<n;i++){
			p[i]=max(0LL,min(r-i,p[l+r-i]));
			while(i-p[i]>=0&&i+p[i]<n&&s[i-p[i]]==s[i+p[i]]){
				p[i]++;
			}
			if(i+p[i]>r){
				l=i-p[i];
				r=i+p[i];
			}
		}
	}
	void build(string s){
		string t;
		for(auto v:s){
			t+=string("#")+v;
		}
		runManacher(t+"#");
	}
	int getMaxLength(int cen,int odd){
		int pos=2*cen+1+(!odd);
		return p[pos]-1;
	}
	int isPalindrome(int l,int r){
		if(r-l+1<=getMaxLength(((l+r)/2),(l&1)==(r&1))){
			return 1;
		}
		return 0;
	}
};
void solve(){
	string s;cin>>s;
	manacher m;
	m.build(s);
	int lmax=0;
	int start=0;
	for(int i=0;i<s.length();i++){
		int lodd=m.getMaxLength(i,1);
		int leven=m.getMaxLength(i,0);
		if(lmax<lodd){
			lmax=lodd;
			start=i-lmax/2;
		}
		if(lmax<leven){
			lmax=leven;
			start=i-lmax/2+1;
		}
	}
	cout<<s.substr(start,lmax)<<nline;
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