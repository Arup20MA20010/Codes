//Given n jobs with there start time and end time we have to find the maximum amount of jobs we can do withhout performing the two jobs at the same time.
/*
No If I do a job that ends early then I would be having a lot more time to decide and devote to the other jobs that I will be doing hence in turn do as maximise the no. of jobs I could do.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n;cin>>n;
	vector<ii>arr(n);
	for(int i=0;i<n;i++){
		int s,e;cin>>s>>e;
		arr[i]={e,s};
	}
	sort(arr.begin(),arr.end());
	int ending=0;
	int cnt=0;
	for(auto p:arr){
		if(p.ss>=ending){
			cnt++;
			ending=p.ff;
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
	return 0;
}