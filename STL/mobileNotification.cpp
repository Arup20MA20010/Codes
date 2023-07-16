#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,q;cin>>n>>q;
	vector<queue<int>>Q(n+1);
	queue<pair<int,int>>mobile;
	int unread=0;
	for(int i=0;i<q;i++){
		int z,x;cin>>z>>x;
		if(z==1){
			mobile.push({i,x});
			Q[x].push(i);
			unread++;
		}else if(z==2){
			while(!Q[x].empty()){
				Q[x].pop();
				unread--;
			}
		}else{
			while(x--){
				pair<int,int>notif=mobile.front();
				if(!Q[notif.second].empty()&&Q[notif.second].front()==notif.first){
					unread--;
					Q[notif.second].pop();
				}
				mobile.pop();
			}
		}
		cout<<unread<<nline;
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
	while(T--)solve();
	return 0;
}