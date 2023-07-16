#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<pair<int,int>,int>;
#define ff first
#define ss second
void solve(){
	int n;cin>>n;
	vector<pii>jobs(n);
	for(int i=0;i<n;i++){
		int s,e,p;cin>>s>>e>>p;
		jobs[i].ff.ff=s;
		jobs[i].ff.ss=e;
		jobs[i].ss=p;
	}
	sort(jobs.begin(),jobs.end(),[](pii a,pii b){
		return a.ff.ff<b.ff.ff;
	});
	int dp[n];
	int ans=0;
	for(int i=n-1;i>=0;i--){
		int j=-1;
		int lo=i+1;int hi=n-1;
		while(hi>=lo){
			int mid=(hi+lo)/2;
			if(jobs[mid].ff.ff>jobs[i].ff.ss){
				j=mid;
				hi=mid-1;
			}else{
				lo=mid+1;
			}
		}
		dp[i]=jobs[i].ss;
		if(j!=-1){
			dp[i]=max(dp[i],dp[j]+jobs[i].ss);
		}
		ans=max(ans,dp[i]);
		if(i+1<n){
			dp[i]=max(dp[i],dp[i+1]);
		}
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