#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
using pii=pair<int,pair<int,int>>;
#define ff first
#define ss second
int n,m;
bool isValid(int x,int y){
	if(x<0||x>=n||y>=m||y<0)return 0;
	return 1;
}
int arr[17][17];
int k;
int cnt;
vector<int>sol;
void rec(int x,int y){
	if(x==n-1&&y==m-1){
		int sum=0;
		for(auto v:sol){
			// cout<<v<<" "
			sum+=v%k;
			sum%=k;
		}
		// cout<<nline;
		sum+=arr[x][y]%k;
		sum%=k;
		if(sum==0)cnt++;
		return;
	}
	if(isValid(x+1,y)){
		sol.push_back(arr[x+1][y]);
		rec(x+1,y);
		sol.pop_back();
	}
	if(isValid(x,y+1)){
		sol.push_back(arr[x][y+1]);
		rec(x,y+1);
		sol.pop_back();
	}
}
void solve(){
	cin>>n>>m;
	cin>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	rec(0,0);
	cout<<cnt<<nline;
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