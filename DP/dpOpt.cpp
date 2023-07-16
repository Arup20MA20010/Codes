#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[100100];
struct montoneDeque{
	deque<int>dq;
	void insert(int x){
		while(!dq.empty()&&dq.back()>x){
			dq.pop_back();
		}
		dq.push_back(x);
	}
	void remove(int x){
		if(dq.front()==x){
			dq.pop_front();
		}
	}
	int getMin(){
		return dq.front();
	}
};
void dequeSolve(){
	int n;
	cin>>n;
	int arr[n];
	int b[n];
	//cost for moving from i ->i+1
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		dp[i]=0;
	}
	montoneDeque md;
	md.insert(dp[0]+b[0]);
	for(int i=1;i<n;i++){
		dp[i]=min(md.getMin()+b[i],arr[i]);
		md.insert(dp[i]+b[i]);
		if(i>=k)md.remove(dp[i-k]+b[i-k]);
	}
	cout<<dp[n-1]<<nline;
}
void solve(){
	int n;
	cin>>n;int k;cin>>k;
	int arr[n];
	int b[n];
	//cost for moving from i ->i+1
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		dp[i]=0;
	}
	multiset<int>mt;
	mt.insert(1e18);
	mt.insert(dp[0]+b[0]);
	for(int i=1;i<n;i++){
		dp[i]=min(dp[i-1]+arr[i-1],*mt.begin()+b[i]);
		mt.insert(dp[i]+b[i]);
		if(mt.size()>k){
			mt.erase(mt.find(dp[i-k]+b[i-k]));
		}
	}
	cout<<dp[n-1]<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();	
	return 0;
}