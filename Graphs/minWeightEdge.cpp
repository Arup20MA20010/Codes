#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<int,pair<int,int>>;
#define ff first
#define ss second
struct UnionFind{
	int n,setSize;
	vector<int>rank;
	vector<int>parent;
	UnionFind(){};
	UnionFind(int n){
		this->n=n;
		setSize=n;
		rank.resize(n+1);
		parent.resize(n+1);
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	int find(int x){
		if(x!=parent[x])return parent[x]=find(parent[x]);
		return x;
	}
	void merge(int x,int y){
		int nodeX=find(x);int nodeY=find(y);
		if(nodeX==nodeY)return;
		if(rank[nodeX]>=rank[nodeY]){
			rank[nodeX]+=rank[nodeY];
			parent[nodeY]=nodeX;
		}else{
			rank[nodeY]+=rank[nodeX];
			parent[nodeX]=nodeY;
		}
		setSize--;
	}
};
void solve(){
	int n;cin>>n;
	vector<pii>edgeList;
	UnionFind s(n);
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edgeList.push_back({w,{u,v}});
	}
	sort(edgeList.begin(),edgeList.end());
	int ans=0;
	reverse(edgeList.begin(),edgeList.end());
	for(auto edge:edgeList){
		int u=edge.ss.ff;
		int v=edge.ss.ss;
		int w=edge.ff;
		int nodeU=s.find(u);
		int nodeV=s.find(v);
		ans+=w*(s.rank[nodeU]*s.rank[nodeV]);
		// cout<<s.setSize<<nline;
		s.merge(u,v);
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
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}