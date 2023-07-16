#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>dist;
void dfs(int node,int distance){
	dist[node]=distance;
	for(auto v:g[node]){
		if(dist[v]!=-1)continue;
		dfs(v,distance+1);
	}
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	dist.assign(n+1,-1);
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	int maxDist=0;
	int farthestNode=0;
	for(int i=2;i<=n;i++){
		if(dist[i]>maxDist){
			farthestNode=i;
			maxDist=dist[i];
		}
	}
	dist.assign(n+1,-1);
	dfs(farthestNode,0);
	int diameter=0;
	for(int i=1;i<=n;i++){
		diameter=max(diameter,dist[i]);
	}
	cout<<diameter<<nline;
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