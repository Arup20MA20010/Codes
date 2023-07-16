#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>b(n);
	int ans=n;
	sort(arr,arr+n);
	int i=0,j=n-1;
	int k=0;
	while(i<j){
		b[k++]=arr[i];
		b[k++]=arr[j];
		i++;
		j--;
	}
	if(i==j){
		b[n-1]=arr[i];
	}
	for(int i=0;i<n;i++){
		if(i>0&&b[i]>b[i-1]){
			ans++;
		}else if(i<n&&b[i]>b[i+1]){
			ans++;
		}
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef OINLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}