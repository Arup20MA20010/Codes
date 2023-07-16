#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int>Fib;
void solve(){
	int k;cin>>k;
	int ans=0;
	while(k>=1){
		auto it=upper_bound(Fib.begin(),Fib.end(),k);
		it--;
		int num=*it;
		ans+=k/num;
		k%=num;
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
	int T;cin>>T;
	Fib.resize(104);
	Fib[0]=1;
	Fib[1]=1;
	for(int i=2;i<104;i++){
		Fib[i]=Fib[i-1]+Fib[i-2];
	}
	while(T--){
		solve();
	}
	return 0;
}