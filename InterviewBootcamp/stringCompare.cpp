#include <bits/stdc++.h>
using namespace std;

bool StringCompare(string s, string t) {
	stack<char>st;
	for(auto ch:s){
		if(ch=='#'){
			if(!st.empty()){
				st.pop();
			}
		}else{
			st.push(ch);
		}
	}
	string ans1;
	while(!st.empty()){
		ans1.push_back(st.top());
		st.pop();
	}

	for(auto ch:t){
		if(ch=='#'){
			if(!st.empty()){
				st.pop();
			}
		}else{
			st.push(ch);
		}
	}
	string ans2;
	while(!st.empty()){
		ans2.push_back(st.top());
		st.pop();
	}
	return ans1==ans2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s, t;
	cin >> s >> t;
	if (StringCompare(s, t))
		cout << "Yes";
	else
		cout << "No";
}