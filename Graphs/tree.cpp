#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>depth;
vector<int>subSz;
vector<int>par;
vector<int>isLeaf;
vector<int>childNo;
void dfs(int node,int parent,int distance){
	depth[node]=distance;
	par[node]=parent;
	subSz[node]=1;
	childNo[node]=0;
	isLeaf[node]=1;
	for(auto v:g[node]){
		if(v!=parent[node]){
			childNo[node]++;
			dfs(v,node,distance+1);
			subSz[node]+=subSz[v];
		}
	}
	if(childNo[node]==0){
		isLeaf[node]=1;
	}
}
void solve(){
	int n;cin>>n;
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