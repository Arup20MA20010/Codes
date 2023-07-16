#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;
	cin>>n;
	int target;cin>>target;
	set<int>st;
	int arr[n];int brr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		st.insert(arr[i]);
	}
	for(int i=0;i<n;i++){
		cin>>brr[i];
		auto it=st.lower_bound(target-arr[i]);
	}

}