#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

void solve(){
	int n;cin>>n;
	int q;cin>>q;
	vector<int>arr(n+1,0);
	vector<int>prefix(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		prefix[i]=arr[i];
		prefix[i]+=prefix[i-1];
	}
	while(q--){
		int l,r;cin>>l>>r;
		cout<<prefix[r]-prefix[l-1]<<nline;
	}
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