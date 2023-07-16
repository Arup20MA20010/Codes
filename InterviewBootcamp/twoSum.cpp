#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
void solve(){
	int n;
	int S;
	cin>>n>>S;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int i=0,j=n-1;
	while(i<j){
		if(arr[i]+arr[j]==S){
			cout<<"Y"<<nline;
			return;
		}else if(arr[i]+arr[j]>S){
			j--;
		}else{
			i++;
		}
	}
	cout<<"N"<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}