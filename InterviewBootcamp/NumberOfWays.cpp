#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	vector<int>factors;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			factors.push_back(i);
			if(i*i!=n)factors.push_back(n/i);
		}
	}
	int cnt=0;
	for(auto k:factors){
		if((k&1)&&(2*n>=k*(k-1)))cnt++;
		if((n%(2*k))!=0&&n>=k*(2*k-1))cnt++;
	}
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