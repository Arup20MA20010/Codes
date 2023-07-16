#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string phone[]={"0","1","abc",
				"def","ghi","jkl",
				"mno","pqrs","tuv",
				"wxyz"};
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
	for(auto ch:phone[num[level]-'0']){
		sol.push_back(ch);
		rec(level+1);
		sol.pop_back();
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
	solve();
	return 0;
}