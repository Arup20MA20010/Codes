#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>ans;
vector<int>a;
vector<int>wsz;
int n;
int rootAns=0;
void dfs(int node,int par,int distance){
	wsz[node]=a[node];
	rootAns+=a[node]*distance;
	for(auto nbrs:g[node]){
		if(nbrs==par)continue;
		dfs(nbrs,node,distance+1);
		wsz[node]+=wsz[nbrs];
	}
}
void dfsans(int node,int par){
	if(node==1){
		ans[node]=rootAns;
	}else{
		ans[node]=ans[par]+wsz[1]-2*wsz[node];
	}
	for(auto nbrs:g[node]){
		if(nbrs==par)continue;
		dfsans(nbrs,node);
	}
}
void solve(){
	cin>>n;
	g.resize(n+1);
	ans.assign(n+1,0);
	wsz.assign(n+1,0);
	a.assign(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	dfsans(1,0);
	int maxval=-1e18;
	int minval=1e18;
	for(int i=1;i<=n;i++){
		maxval=max(maxval,ans[i]);
		minval=min(minval,ans[i]);
	}
	cout<<maxval<<" "<<minval<<nline;
	rootAns=0;
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