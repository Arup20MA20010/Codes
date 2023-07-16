#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<n;i++){
		int length;cin>>length;
		pq.push(length);
	}
	int cost=0;
	while(!pq.empty()){
		int l1=pq.top();
		pq.pop();
		if(pq.empty())break;
		int l2=pq.top();
		pq.pop();
		pq.push(l1+l2);
		cost+=(l1+l2);
	}
	cout<<cost<<nline;
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