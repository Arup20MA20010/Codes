#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>depth;
vector<vector<int>>par;
vector<vector<int>>dp;
vector<int>val;
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	return gcd(b,a%b);
}
void dfs(int node,int parent,int dist){
	par[node][0]=parent;
	dp[node][0]=val[node];
	depth[node]=dist;
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
		dp[node][i]=gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
	}
	for(auto nbrs:g[node]){
		if(nbrs==parent)continue;
		dfs(nbrs,node,dist+1);
	}
}
int pathGCD(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	int ans=0;
	//first taking u to the level of v
	for(int i=19;i>=0;i--){
		if(((depth[u]-depth[v])>>i)&1){
			ans=gcd(ans,dp[u][i]);
			u=par[u][i];
		}+
	}
	if(u==v)return gcd(val[u],ans);
	//now we take the gcd till lca
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ans=gcd(ans,dp[u][i]);
			ans=gcd(ans,dp[v][i]);
			u=par[u][i];
			v=par[v][i];
		}
	}
	ans=gcd(gcd(val[u],val[v]),ans);
	return gcd(val[par[u][0]],ans);
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	depth.assign(n+1,0);
	val.assign(n+1,0);
	par.assign(n+1,vector<int>(21,0));
	dp.assign(n+1,vector<int>(21,0));
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		cout<<pathGCD(x,y)<<nline;
	}
	g.clear();
	depth.clear();
	val.clear();
	par.clear();
	dp.clear();
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