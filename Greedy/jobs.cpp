#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct Job {
    int deadline, duration;
};

void solve(){
	int n;cin>>n;
	vector<Job>v(n);
	for(int i=0;i<n;i++){
		int d;cin>>d;
		v[i].deadline=d;
	}
	for(int i=0;i<n;i++){
		int l;cin>>l;
		v[i].duration=l;
	}
	sort(v.begin(),v.end(),[&](Job a,Job b){
		if(a.deadline==b.deadline){
			return a.duration<b.duration;
		}
		return a.deadline<b.deadline;
	});
	int cnt=0;
	set<pair<int,int>>st;
	for(int i=n-1;i>=0;i--){
		int t=v[i].deadline-(i?v[i-1].deadline:0);
		st.insert({v[i].duration,i});
		while(t&&!st.empty()){
			auto it=st.begin();
			if(t>=it->first){
				t-=it->first;
				cnt++;
			}else{
				st.insert({it->first-t,it->second});
				t=0;
			}
			st.erase(it);
		}
	}
	cout<<cnt<<nline;
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
}