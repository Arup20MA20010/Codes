#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<pair<int,int>>>g;
vector<int>depth;
vector<vector<int>>par;
vector<int>prefix;
void dfs(int node,int parent,int dist,int val){
	par[node][0]=parent;
	prefix[node]=val+prefix[parent];
	depth[node]=dist;
	for(auto nbrs:g[node]){
		if(nbrs.first==parent)continue;
		dfs(nbrs,node,dist+1,nbrs.second);
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	//taking u to the same level as v
	for(int i=19;i>=0;i--){
		if(((depth[u]-depth[v])>>i)&1){
			u=par[u][i];
		}
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int pathSum(int u,int v){
	return prefix[u]+prefix[v]-2*prefix[lca(u,v)];
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	prefix.assign(n+1,0);
	par.assign(n+1,vector<int>(21,0));
	depth.assign(n+1,0);
	for(int i=0;i<n;i++)
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