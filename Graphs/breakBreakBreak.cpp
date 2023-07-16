#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n,k;
bool check(int x,int maxVal,int sum){
	return x*(n+k)>=sum;
}
void solve(){
	cin>>n;
    cin>>k;
	vector<int>arr(n,0);
	int sum=0;
	int maxEl=-1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		maxEl=max(maxEl,arr[i]);
	}
	int ans=-1;
	int lo=0;int hi=maxEl;
	while(lo<=hi){
		int mid=(hi+lo)/2;
		if(check(mid,sum)){
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
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}