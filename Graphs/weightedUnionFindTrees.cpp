#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
struct UnionFind{
	int n;
	vector<ii>parent;//(parent,diff)
	vector<int>rank;
	UnionFind(){};
	UnionFind(int n){
		this->n=n;
		parent.resize(n);
		rank.resize(n);
		for(int i=0;i<n;i++){
			rank[i]=0;
			parent[i]={i,0};
		}
	}
	ii find(int x){
		if(x!=parent[x].ff){
			ii val=find(parent[x].ff);
			parent[x].ss+=val.ss;
			parent[x].ff=val.ff;
			return parent[x];
		}
		return parent[x];
	}
	//y-x=z;
	//parent->(parent,parent-child)
	void merge(int x,int y,int z){
		ii nodeX=find(x);ii nodeY=find(y);
		if(nodeX.ff==nodeY.ff)return;
		if(rank[nodeX.ff]>=rank[nodeY.ff]){
			rank[nodeX.ff]+=rank[nodeY.ff];
			parent[nodeY.ff].ff=nodeX.ff;
			parent[nodeY.ff].ss=nodeX.ss-nodeY.ss-z;
		}else{
			rank[nodeY.ff]+=rank[nodeX.ff];
			parent[nodeX.ff].ff=nodeY.ff;
			parent[nodeX.ff].ss=nodeY.ss-nodeX.ss+z;
		}
	}
};
void solve(){
	int n,q;cin>>n>>q;
	UnionFind s(n);
	while(q--){
		int ch;cin>>ch;
		if(ch==1){
			int x,y;cin>>x>>y;
			ii nodeX=s.find(x);
			ii nodeY=s.find(y);
			if(nodeX.ff!=nodeY.ff){
				cout<<"?"<<nline;
			}else{
				cout<<nodeX.ss-nodeY.ss<<nline;
			}
		}else{
			int x,y,z;cin>>x>>y>>z;
			s.merge(x,y,z);
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
	solve();
	return 0;
}