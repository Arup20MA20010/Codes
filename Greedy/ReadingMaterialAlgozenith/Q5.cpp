#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int k;cin>>k;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		pq.push(x);
	}
	while(k--){
		int p=pq.top();
		p*=-1;
		pq.pop();
		pq.push(p);
	}
	int sum=0;
	while(!pq.empty()){
		sum+=pq.top();
		pq.pop();
	}
	cout<<sum<<nline;
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