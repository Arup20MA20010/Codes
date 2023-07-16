#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,m;cin>>n>>m;
	map<string,int>mp;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int mask=0;mask<=(1<<m)-1;i++){
			string temp="";
			for(int i=0;i<m;i++){
				if((mask>>i)&1){
					temp.push_back('?');
				}else{
					temp.push_back(s[i]);
				}
			}
			mp[temp]++;
		}
	}
	int q;cin>>q;
	while(q--){
		string pos;
		cin>>pos;
		if(mp.find(pos)!=mp.end()){
			cout<<mp[pos]<<nline;
		}else{
			cout<<0<<nline;
		}
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