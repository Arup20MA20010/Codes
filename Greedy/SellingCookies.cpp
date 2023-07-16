#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int maxVal=0;
	int sum=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		maxVal=max(maxVal,x);
		sum+=x;
	}
	sum-=maxVal;
	if(sum<=maxVal){
		cout<<maxVal-sum<<nline;
		return;
	}
	cout<<((sum-maxVal)&1)<<nline;
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