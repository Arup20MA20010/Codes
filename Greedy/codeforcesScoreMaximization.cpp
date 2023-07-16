#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct prob{
	int s,t,d;
};
bool compare(prob a,prob b){
	return a.t*b.d<a.d*b.t;
}
void solve(){
	int n;cin>>n;
	vector<prob>arr(n);
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		arr[i]={x,y,z};
	}
	sort(arr.begin(),arr.end(),compare);
	int sum=0;
	int score=0;
	for(int i=0;i<n;i++){
		sum+=arr[i].t;
		score+=(arr[i].s-sum*arr[i].d);
	}
	cout<<score<<nline;
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