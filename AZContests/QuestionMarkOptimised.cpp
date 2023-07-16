#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
map<string,int>mp;
void solve(){
	int n,m;cin>>n>>m;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int mask=0;mask<(1<<m);mask++){
			string ans;
			for(int j=0;j<m;j++){
				if((mask>>j)&1){
					ans.push_back('?');
				}else{
					ans.push_back(s[j]);
				}
			}
			mp[ans]++;
		}
	}
	int q;cin>>q;
	while(q--){
		string _s;
		cin>>_s;
		cout<<mp[_s]<<nline;
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