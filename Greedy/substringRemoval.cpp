#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;
	int x,y;
	cin>>s>>x>>y;
	/*
	We remove the substring with the highest score
	*/
	int hs=max(x,y);
	int ms=min(x,y);
	string p1,p2;
	if(x>=y){
		p1="ab";
		p2="ba";
	}else{
		p1="ba";
		p2="ab";
	}
	int score=0;
	stack<char>st;
	for(int i=s.length()-1;i>=0;i--){
		st.push(s[i]);
	}
	stack<char>temp;
	while(!st.empty()){
		while(!st.empty()&&st.top()!=p1[1]){
			temp.push(st.top());
			st.pop();
		}
		if(st.empty())break;
		if(!temp.empty()&&temp.top()==p1[0]){
			score+=hs;
			temp.pop();
		}else{
			temp.push(st.top());
		}
		st.pop();
	}
	// cout<<"hello"<<nline;
	// while(!temp.empty()){
	// 	cout<<temp.top();
	// 	temp.pop()<<" nline";
	// }
	while(!temp.empty()){
		while(!temp.empty()&&temp.top()!=p1[1]){
			st.push(temp.top());
			temp.pop();
		}
		if(temp.empty())break;
		if(!st.empty()&&st.top()==p1[0]){
			score+=ms;
			temp.pop();
			st.pop();
		}else{
			st.push(temp.top());
			temp.pop();
		}
	}
	cout<<score<<nline;
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