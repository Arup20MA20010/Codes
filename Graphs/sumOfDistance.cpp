#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<vector<int>>g;
vector<int>succ;
vector<int>dist;
void dfs(int node,int distance){
	dist[node]=distance;
	for(auto nbrs:g[node]){
		if(dist[nbrs]!=-1)continue;
		dfs(nbrs,distance+1);
		succ[node]+=succ[nbrs];
	}
}
void solve(){
	int n;cin>>n;
	dist.assign(n+1,-1);
	succ.assign(n+1,1);
	g.resize(n+1);
	vector<ii>edgeList;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		edgeList.push_back({a,b});
	}
	dfs(1,0);
	int ans=0;
	for(auto edge:edgeList){
		int a=edge.ff;
		int b=edge.ss;
		if(dist[a]>dist[b]){
			ans+=(succ[a]*(n-succ[a]));
		}else{
			ans+=(succ[b]*(n-succ[b]));
		}
	}
	cout<<ans<<nline;
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