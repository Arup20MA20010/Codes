#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int A[n];
	for(int i=0;i<n;i++)cin>>A[i];
	int i=0,j=n-1;
	int maxAns=0;
	while(i<=j){
		maxAns=max(maxAns,min(A[i],A[j])*abs(i-j));
		if(A[i]>=A[j]){
			j--;
		}else{
			i++;
		}
	}
	cout<<maxAns<<nline;
	
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