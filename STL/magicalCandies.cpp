#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,k;cin>>n>>k;
	priority_queue<int>pq;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		pq.push(x);
	}
	int ans=0;
	while(k--){
		int temp=pq.top();pq.pop();
		ans+=temp;
		pq.push(temp/2);
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
	}
}