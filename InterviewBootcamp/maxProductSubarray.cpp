#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int prefix[n+1];
	prefix[0]=1;
	int minAns=1e18;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		prefix[i]=x*prefix[i-1];
		minAns=min(minAns,x);
	}
	set<int>stPos;
	set<int>stNeg;
	int maxAns=-1e18;
	stPos.insert(prefix[0]);
	for(int i=1;i<=n;i++){
		if(prefix[i]>=0){
			int l=*stPos.begin();
			maxAns=max(maxAns,prefix[i]/l);
			if(prefix[i]>0)
				stPos.insert(prefix[i]);
		}else if(prefix[i]<0){
			if(stNeg.empty()){
				stNeg.insert(-1*prefix[i]);
				continue;
			}
			int l=*stNeg.begin();
			maxAns=max(maxAns,-1*prefix[i]/l);
			stNeg.insert(-1*prefix[i]);
		}

	}
	cout<<max(maxAns,minAns)<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}