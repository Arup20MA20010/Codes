#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	vector<int>primes;
	int ans=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			primes.push_back(i);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		primes.push_back(n);
	}
	for(auto p:primes){
		ans/=p;
	}
	for(auto p:primes){
		ans*=(p-1);
	}
	cout<<ans<<nline;
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