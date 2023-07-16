/*
given two n dimensional vectors we have to find the maximise the dot products given we can rearrange the elements of the vectors.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	sort(a,a+n);
	sort(b,b+n);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i]*b[i];
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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