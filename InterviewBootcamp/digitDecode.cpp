#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string num;
vector<char>sol;
int n;
void rec(int level){
	if(level==n){
		for(auto x:sol){
			cout<<x;
		}
		cout<<nline;
		return;
	}
	//taking only the char
	if((num[level]-'0')!=0){
		int pos=(num[level]-'0')-1;
		char ch='A'+pos;
		sol.push_back(ch);
		rec(level+1);
		sol.pop_back();
	}
	if(num[level]<='2'&&(level<n-1)){
		int pos=(num[level]-'0')*10+(num[level+1]-'0');
		pos--;
		if(pos<26){
			char ch='A'+pos;
			sol.push_back(ch);
			rec(level+2);
			sol.pop_back();
		}
	}
}
void solve(){
	cin>>num;
	n=num.length();
	rec(0);
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