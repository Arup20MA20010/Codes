#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,k;cin>>n>>k;
	int pos[k];
	int prefix[n+1];
	prefix[0]=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		prefix[i]=x+prefix[i-1];
		prefix[i]=(prefix[i]%k+k)%k;
		pos[prefix[i]]=i;
	}
	int maxL=0;
	for(int i=0;i<=n;i++){
		int j=pos[prefix[i]];
		maxL=max(maxL,j-i);
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
	solve();
	return 0;
}