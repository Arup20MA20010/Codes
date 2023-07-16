#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int>kmp(string s){
	int n=s.length();
	vector<int>res(n+1);
	res[0]=-1;
	int i=0,j=-1;
	while(i<n){
		while(j!=-1&&s[i]!=s[j]){
			j=res[j];
		}
		i++;
		j++;
		res[i]=j;
	}
	return res;
}
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int>kmpArr=kmp(s);
	// for(auto x:kmpArr){
	// 	cout<<x<<" ";
	// }
	// cout<<nline;
	for(int i=0;i<n;i++){
		int p=(i+1)-kmpArr[i+1];
		if(p!=(i+1)&&(i+1)%p==0){
			cout<<i+1<<" "<<(i+1)/p<<nline;
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
	for(int i=1;i<=T;i++){
		cout<<"Test case #"<<i<<nline;
		solve();
		cout<<nline;
	}
	return 0;
}