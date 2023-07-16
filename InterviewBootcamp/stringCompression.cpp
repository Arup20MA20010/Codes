#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	char symbol[62];
	for(int i=0;i<26;i++){
		symbol[i]=('a'+i);
	}
	for(int i=26;i<52;i++){
		symbol[i]=('A'+i-26);
	}
	for(int i=52;i<62;i++){
		symbol[i]=('0'+i-52);
	}
	string ans;
	while(n){
		ans.push_back(symbol[n%62]);
		n/=62;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<nline;
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