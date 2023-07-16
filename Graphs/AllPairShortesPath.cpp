#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int mat[501][501];
int arr[501];
int dist[501][501];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mat[i][j];
			dist[i][j]=mat[i][j];
		}
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stack<int>st;
	for(int k=n-1;k>=0;k--){
		//relaxing the distance from i to k
		int sum=0;
		for(int i=n-1;i>k;i--){
			int ans=1e18;
			for(int j=n-1;j>k;j--){
				if(i!=j){
					ans=min(ans,dist[arr[i]][arr[j]]+mat[arr[j]][arr[k]]);
				}
			}
			dist[arr[i]][arr[k]]=min(ans,mat[arr[i]][arr[k]]);
		}
		//relaxing the distance to all other nodes 
		for(int i=n-1;i>k;i--){
			for(int j=n-1;j>k;j--){
				if(i!=j){
					dist[arr[i]][arr[j]]=min(dist[arr[i]][arr[k]]+dist[arr[k]][arr[j]],dist[arr[i]][arr[j]]);
				}
			}
		}
		for(int i=n-1;i>=k;i--){
			for(int j=n-1;j>=k;j--){
				sum+=dist[arr[i]][arr[j]];
			}
		}

		st.push(sum);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
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