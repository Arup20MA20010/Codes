#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n,L;cin>>n>>L;
	map<int,int>contribution;
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		contribution[l]++;
		contribution[r]--;
	}
	
	int cnt=0;
	int minCnt=1e9;
	for(auto v:contribution){
		if(v.ff!=L){
			minCnt=min(minCnt,cnt+v.ss);
			cnt+=v.ss;
			// cout<<cnt<<nline;
		}
	}
	cout<<n-minCnt+1<<nline;
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