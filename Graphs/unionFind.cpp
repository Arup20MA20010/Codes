#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct unionFind{
	int n,set_size;
	vector<int>parent;
	vector<int>rank;
	unionFind(){}
	unionFind(int a){
		n=set_size=a;
		parent.resize(n+1);
		rank.reisze(n+1);
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	int find(x){
		if(x!=parent[x])return parent[x]=find(parent[x]);
		return x;
	}
	void merge(int x,int y){
		int nodeX=find(x),nodeY=find(y);
		if(nodeX==nodeY)return;
		if(rank[nodeX]>=rank[nodeY]){
			rank[nodeX]+=rank[nodeY];
			parent[nodeY]=nodeX;
		}else{
			rank[nodeY]+=rank[nodeX];
			parent[nodeX]=nodeY;
		}
		set_size--;
	}
	void reset(){
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	void getSize(){
		return setSize;
	}
};
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
	while(T--){
		solve();
	}
	return 0;
}