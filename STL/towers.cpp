#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int count=0;
	multiset<int>mt;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(mt.empty()||mt.upper_bound(x)==mt.end()){
			mt.insert(x);
			count++;
		}else{
			auto it=mt.upper_bound(x);
			mt.erase(it);
			mt.insert(x);
		}
	}
	cout<<count<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}