#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>outDeg;
void solve(){
	int n;cin>>n;
	int m;cin>>m;
	g.resize(n+1);
	outDeg.assign(n+1,0);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		outDeg[u]++;
	}
	priority_queue<int>pq;
	for(int i=1;i<=n;i++){
		if(outDeg[i]==0)pq.push(i);
	}
	vector<int>topo;
	while(!pq.empty()){
		int curr=pq.top();
		pq.pop();
		topo.push_back(curr);
		for(auto nbrs:g[curr]){
			outDeg[nbrs]--;
			if(outDeg[nbrs]==0){
				pq.push(nbrs);
			}
		}
	}
	reverse(topo.begin(),topo.end());
	vector<int>pos(topo.size()+1);
	// for(auto x:topo){
	// 	cout<<x<<" ";
	// }
	// cout<<nline;
	for(int i=0;i<topo.size();i++){
		pos[topo[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		cout<<pos[i]<<" ";
	}
	cout<<nline;
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