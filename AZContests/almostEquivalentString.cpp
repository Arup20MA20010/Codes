#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s,t;cin>>s>>t;
	if(t.length()!=s.length()){
		cout<<"NO"<<nline;
		return;
	}
	int n=s.length();
	vector<int>o1(26,0);
	vector<int>o2(26,0);
	for(int i=0;i<n;i++){
		o1[s[i]-'a']++;
		o2[t[i]-'a']++;
	}
	bool Ok=1;
	for(int i=0;i<26;i++){
		if(abs(o1[i]-o2[i])>3){
			Ok=0;
			break;
		}
	}
	if(Ok){
		cout<<"YES"<<nline;
	}else{
		cout<<"NO"<<nline;
	}
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