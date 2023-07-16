#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int x,y;cin>>x>>y;
	int cnt=0;
	while(y>x){
		if(y%2){
			y++;cnt++;
		}
		y/=2;
		cnt++;
	}
	cnt+=(x-y);
	cout<<cnt<<nline;
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