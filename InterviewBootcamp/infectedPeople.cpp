#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int n,m;
int isValid(int i,int j){
	if(i<0||j<0||i>=n||j>=m)return 0;
	return 1;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	vector<vector<int>>dist(n,vector<int>(m,1e18));
	// vector<vector<int>>visited(n,vector<int>(m,0));
	queue<ii>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				q.push({i,j});
				dist[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int x=curr.ff;
		int y=curr.ss;
		// if(visited[x][y])continue;
		// visited[x][y]=1;
		for(int dir=0;dir<4;dir++){
			int xx=x+dx[dir];
			int yy=y+dy[dir];
			if(isValid(xx,yy)&&(arr[xx][yy]==1)&&dist[xx][yy]>dist[x][y]+1){
				dist[xx][yy]=dist[x][y]+1;
				q.push({xx,yy});
			}
		}
	}

	int maxVal=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1)maxVal=max(maxVal,dist[i][j]);
		}
	}
	cout<<(maxVal!=1e18?maxVal:-1)<<nline;
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