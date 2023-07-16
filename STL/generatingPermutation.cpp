#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	vector<int>v(n,0);
	for(int i=0;i<n;i++){
		v[i]=i+1;
	}
	do{
		for(int i=0;i<n;i++){
			cout<<v[i]<<" ";
		}
		cout<<nline;
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}