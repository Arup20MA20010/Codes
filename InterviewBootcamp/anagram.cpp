#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s,t;cin>>s>>t;
	multiset<char>st;
	for(auto ch:s){
		st.insert(ch);
	}
	bool ok=0;
	for(auto ch:t){
		if(st.find(ch)==st.end()){
			ok=1;
			break;
		}else{
			st.erase(st.find(ch));
		}
	}
	if(!st.empty()||ok){
		cout<<"N"<<nline;
		return;
	}
	cout<<"Y"<<nline;
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