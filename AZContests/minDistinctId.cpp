#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int freq[1001001];
int m;
int k;
int arr[100100];
int n;
bool check(int x){
	int sum=0;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<n;i++){
		pq.push(freq[arr[i]]);
	}
	for(int i=0;i<k-x;i++){
		sum+=pq.top();
		pq.pop();
	}
	return sum<=m;
}
void solve(){
	cin>>n;
	cin>>m;
	set<int>st;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		freq[arr[i]]++;
		st.insert(arr[i]);
	}
	k=st.size();
	int lo=0;int hi=k;
	int ans=-1;
	// for(int i=lo;i<=hi;i++){
	// 	// cout<<check(i);
	// 	cout<<freq[i]<<nline;
	// }
	while(hi>=lo){
		int mid=(lo+hi)/2;
		if(check(mid)){
			ans=mid;
			hi=mid-1;
		}else{
			lo=mid+1;
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
	int T;cin>>T;
	while(T--)solve();
	return 0;
}