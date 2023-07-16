#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,k;cin>>n>>k;
	vector<int>s;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		s.push_back(x);
	}
	queue<char>q;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==((q.size()&1)?1:0)){
			ans++;
			q.push(i+k-1);
		}
		if(!q.empty()&&i<=q.front())q.pop();
	}
	if(n==0){
		cout<<0<<nline;
		return;
	}
	cout<<(q.empty()?ans:-1)<<nline;
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