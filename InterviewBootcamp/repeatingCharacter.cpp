#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	vector<int>freq(26);
	string s;cin>>s;
	int n=s.length();
	vector<int>sz(n,1);
	int maxL=0;
	for(int i=0;i<n;i++){
		freq[s[i]-'a']++;
		if(i){
			if(s[i]==s[i-1]){
				sz[i]=sz[i-1]+1;
			}
		}
		maxL=max(maxL,sz[i]);
	}

	for(int i=n-2;i>=0;i--){
		if(s[i]==s[i+1])
			sz[i]=sz[i+1];
	}
	for(int i=0;i<n;i++){
		if(i&&s[i-1]!=s[i]){
			int l=sz[i-1]+(freq[s[i-1]-'a']>sz[i-1]);
			maxL=max(l,maxL);
		}
		if(i<n-1&&s[i]!=s[i+1]){
			int l=sz[i+1]+(freq[s[i+1]-'a']>sz[i+1]);
			maxL=max(l,maxL);
		}
		if(i&&i<n-1&&s[i]!=s[i+1]&&s[i]!=s[i-1]&&s[i-1]==s[i+1]){
			int l=sz[i+1]+sz[i-1]+(freq[s[i+1]-'a']>sz[i+1]+sz[i-1]);
			maxL=max(l,maxL);
		}
	}
	cout<<maxL<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}