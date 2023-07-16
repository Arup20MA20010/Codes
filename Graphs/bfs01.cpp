#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>dist;
vector<int>visited;
int n;
void bfs01(int src){
	dist.assign(n+1,1e9);
	visited.assign(n+1,0);
	visited[src]=1;
	dist[src]=0;
	deque<int>dq;
	dq.push_back(src);
	while(!dq.empty()){
		int curr=dq.front();
		dq.pop_front();
		if(visited[curr])continue;
		visited[curr]=1;
		for(auto nbrs:g[curr]){
			
		}
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