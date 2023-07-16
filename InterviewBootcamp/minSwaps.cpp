#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
vector<int>dist;
vector<int>parent;
void dfs(int src,int par,int distance){
	if(src>n)return;
	dist[src]=distance;
	parent[src]=par;
	dfs(2*src,src,distance+1);
	//going right
	dfs(2*src+1,src,distance+1);
}
void solve(){
	cin>>n;
	dist.assign(n+1,0);
	parent.resize(n+1);
	dfs(1,0,0);
	int a,b;cin>>a>>b;
	vector<int>chain1;
	vector<int>chain2;
	int temp=a;
	while(temp!=0){
		chain1.push_back(temp);
		temp=parent[temp];
	}
	temp=b;
	while(temp!=0){
		chain2.push_back(temp);
		temp=parent[temp];
	}
	int lca=1;
	for(int i=0;i<min(chain1.size(),chain2.size());i++){
		if(chain1[i]==chain2[i]){
			lca=i;
		}else{
			break;
		}
	}
	int d1=dist[a]-dist[lca];
	int d2=dist[b]-dist[lca];
	cout<<"a: "<<dist[a]<<nline;
	cout<<lca<<nline;
	cout<<dist[lca]<<nline;
	cout<<"b: "<<dist[b]<<nline;
	cout<<d1+d2<<nline;
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