#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int>arr;
int n;
vector<int>visited;
vector<vector<int>>g;
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	return gcd(b,a%b);
}
void dfs(int node){
	visited[node]=1;
	for(int j=node+1;j<=n;j++){
		if(visited[j]||gcd(arr[node-1],arr[j-1])<=1)continue;
		g[node].push_back(j);
		dfs(j);
	}
}
void solve(){
	cin>>n;
	arr.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	visited.assign(n+1,0);
	g.resize(n+1);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
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
	while(T--)solve();
	return 0;
}