#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
bool compare(ii a,ii b){
	return a.ss*b.ff<=b.ss*a.ff;
}
void solve(){
	int m;cin>>m;
	int ans=0;
	vector<ii>arr;
	for(int i=0;i<m;i++){
		string s;cin>>s;
		int numZero=0;
		int numOne=0;
		for(auto ch:s){
			if(ch=='0'){
				ans+=numOne;
				numZero++;
			}else{
				numOne++;
			}
		}
		arr.push_back({numZero,numOne});
	}
	sort(arr.begin(),arr.end(),compare);
	int Ones=0;
	for(auto p:arr){
		cout<<p.ff<<" "<<p.ss<<nline;
		ans+=Ones*p.ff;
		Ones+=p.ss;
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
	while(T--){
		solve();
	}
	return 0;
}