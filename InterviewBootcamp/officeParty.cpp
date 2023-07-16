#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>deg;
vector<int>visited;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	cout<<n<<" "<<m<<" "<<k<<nline;

	g.resize(n+1);
	deg.assign(n+1,0);
	visited.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(deg[i]<k){
			q.push(i);
		}
	}
	// int removeDeg=0;
	while(!q.empty()){
		// removeDeg++;
		int node=q.front();
		q.pop();
		visited[node]=1;
		for(auto nbrs:g[node]){
			if(visited[nbrs])continue;
			deg[nbrs]-=1;
			if(deg[nbrs]<k){
				q.push(nbrs);
			}
		}
	}
	// cout<<num<<nline;
	int cnt=0;
	int maxDeg=-1e18;
	int cnt2=0;
	for(int i=1;i<=n;i++){
		// cout<<deg[i]<<nline;
		maxDeg=max(maxDeg,deg[i]);
		cnt+=(deg[i]>=k);
		// cnt+=(deg[i]<=k);
	}
	cout<<maxDeg<<nline;
	cout<<cnt<<nline;
	g.clear();
	deg.clear();
	visited.clear();
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