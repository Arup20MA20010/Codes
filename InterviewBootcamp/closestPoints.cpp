#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pipii=pair<int,pair<int,int>>;
#define ff first
#define ss second
void solve(){
	priority_queue<pipii>pq;
	int n;cin>>n;int x,y;
	int k;cin>>k;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		pq.push({(x*x+y*y),{x,y}});
		if(pq.size()>k){
			pq.pop();
		}
	}
	// while(!pq.empty()){
	// 	auto x=pq.top();
	// 	cout<<x.ss.ff<<" "<<x.ss.ss<<nline;
	// 	pq.pop();
	// }
	stack<pair<int,int>>st;
	while(!pq.empty()){
		st.push(pq.top().ss);
		pq.pop();
	}
	while(!st.empty()){
		pair<int,int>x=st.top();
		cout<<x.ff<<" "<<x.ss<<nline;
		st.pop();		
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}