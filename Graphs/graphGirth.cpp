#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>dist;
int bfs(int src){
	int cycleLen=1e18;
	queue<int>q;
	dist[src]=0;
	q.push(src);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto nbrs:g[node]){
			if(dist[nbrs]>=dist[node]){
				cycleLen=min(1+dist[node]+dist[nbrs],cycleLen);
			}
			if(dist[nbrs]==-1){
				dist[nbrs]=dist[node]+1;
				q.push(nbrs);
			}
		}
	}
	return cycleLen;
}
void solve(){
	int n,m;cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dist.assign(n+1,-1);
	int ans=1e18;
	for(int i=1;i<=n;i++){
		ans=min(ans,bfs(i));
		dist.assign(n+1,-1);
	}
	// cout<<ans<<nline;
	cout<<(ans!=1e18?ans:-1)<<nline;
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