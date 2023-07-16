#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n,q;cin>>n>>q;
	deque<int>dq;
	int maxVal=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		maxVal=max(x,maxVal);
		dq.push_back(x);
	}
	int count=0;
	vector<ii>ans;
	ans.push_back({-1,-1});
	while(dq.front()!=maxVal){
		int a=dq.front();
		dq.pop_front();
		int b=dq.front();
		dq.pop_front();
		count++;
		ans.push_back({a,b});
		dq.push_front(max(a,b));
		dq.push_back(min(a,b));
	}

	while(q--){
		int x;cin>>x;
		if(x<=count){
			cout<<ans[x].ff<<" "<<ans[x].ss<<nline;
		}else{
			int idx=(x-count-1)%(n-1)+1;
			cout<<maxVal<<" "<<dq[idx]<<nline;
		}
	}
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