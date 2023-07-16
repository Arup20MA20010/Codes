#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	string t;cin>>t;
	vector<int>freq(26,0);
	for(auto ch:t)
		freq[ch-'a']++;
	int head=-1;int tail=0;
	int n=s.length();
	int taken=0;
	vector<int>cnt(26,0);
	int start=-1;int len=1e18;
	while(tail<n){
		while(head+1<n&&taken<t.length()){
			if(cnt[s[head+1]-'a']<freq[s[head+1]-'a']){
				taken++;
			}
			cnt[s[head+1]-'a']++;
			head++;
		}
		if(head>=tail&&len>head-tail+1&&taken==t.length()){
			len=head-tail+1;
			start=tail;
		}
		if(head>=tail){
			cnt[s[tail]-'a']--;
			if(cnt[s[tail]-'a']<freq[s[tail]-'a'])
				taken--;
			tail++;
		}else{
			tail++;
			head=tail-1;
			taken=0;
		}
	}
	cout<<s.substr(start,len)<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caseNo;cin>>caseNo;
	while(caseNo--){
		solve();
	}
	return 0;
}