#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	set<int>st;
	int arr[1502];
	arr[0]=1;
	int i=1;
	st.insert(2);
	st.insert(3);
	st.insert(5);
	auto it=st.begin();
	while(i<=1500){
		arr[i]=(*it)*arr[0];
		for(int j=1;j<=i;j++){
			st.insert((*it)*arr[j]);
		}
		i++;it++;
	}
	int n;int t;
	cin>>t;
	// cout<<arr[1500]<<nline;
	while(t--){
		cin>>n;
		cout<<arr[n-1]<<nline;
	}
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