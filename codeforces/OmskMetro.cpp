#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<int>dist;
vector<int>maxdist;
vector<int>mindist;
vector<vector<ii>>g;
void dfs(int node,int d,int d1,int d2,int par,int maxdist1,int maxdist2){
	dist[node]=d;
	maxdist[node]=max(maxdist1,d1);
	mindist[node]=-1*max(maxdist2,d2);
	for(auto nbrs:g[node]){
		if(nbrs.ff==par)continue;
		d1+=nbrs.ss;
		d2-=nbrs.ss;
		if(d1<0)d1=0;
		if(d2<0)d2=0;
		maxdist1=max(d1,maxdist1);
		maxdist2=max(d2,maxdist2);
		dfs(nbrs.ff,d+nbrs.ss,d1,d2,node,maxdist1,maxdist2);
	}
}
void solve(){
	int q;
	vector<ii>query;
	vector<ii>addition;
	cin>>q;
	while(q--){
		char ch;cin>>ch;
		if(ch=='+'){
			int v,x;cin>>v>>x;
			// cout<<v<<" "<<x<<nline;
			addition.push_back({v,x});
		}else if(ch=='?'){
			int u,v,k;cin>>u>>v>>k;
			query.push_back({v,k});
		}
	}
	int n=addition.size();
	g.resize(n+2);
	dist.assign(n+2,0);
	maxdist.assign(n+2,0);
	mindist.assign(n+2,0);
	for(int i=0;i<n;i++){
		int v=addition[i].ff;
		int x=addition[i].ss;
		int valv=(v==1?1:addition[v-2].ss);
		g[v].push_back({i+2,valv+x});
		g[i+2].push_back({v,valv+x});
	}
	// for(int i=1;i<=n+1;i++){
	// 	cout<<i<<" -> ";
	// 	for(auto nbrs:g[i]){
	// 		cout<<"( "<<nbrs.ff<<", "<<nbrs.ss<<" )"<<" ";
	// 	}
	// 	cout<<nline;
	// }
	dfs(1,0,0,0,0,0,0);
	for(auto x:query){
		int v=x.ff;
		int k=x.ss;
		if(k==1){
			cout<<"YES"<<nline;
			continue;
		}
		if(mindist[v]<=k&&k<=maxdist[v]){
			cout<<"YES"<<nline;
		}else{
			cout<<"NO"<<nline;
		}
	}
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