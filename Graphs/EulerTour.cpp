#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int timer;
vector<int>inTime;
vector<int>outTime;
vector<vector<int>>g;
void dfs(int node,int par){
	inTime[node]=++timer;
	for(auto nbrs:g[node]){
		if(nbrs==par)continue;
		dfs(nbrs,node);
	}
	outTime[node]=++timer;
}
bool isAncestor(int u,int v){
	if(inTime[u]<=inTime[v]&&outTime[u]>=outTime[v])return 1;
	return 0;
}
void solve(){

}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}