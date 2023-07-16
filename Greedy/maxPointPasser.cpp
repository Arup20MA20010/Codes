/*
Some incorrectness in the code to be checked
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define  nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	return gcd(b%a,a);
}
ii getReducedFraction(int a,int b){
	if(a==0&&b==0)return {0,0};
	int neg=1;
	if(a<0)neg*=-1;
	if(b<0)neg*=-1;
	int x=gcd(neg*a,neg*b);
	return {a/x,neg*b/x};
}
void solve(){
	int n;cin>>n;
	vector<ii>points;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		points.push_back({x,y});
	}
	ii point1,point2;
	int maxAns=0;
	for(int i=0;i<n;i++){
		map<ii,int>mp;
		int same=0;
		for(int j=0;j<n;j++){
			if(points[i].ff=points[j].ff||points[i].ss==points[j].ss){
				same++;
			}else{
				ii slope=getReducedFraction(points[i].ss-points[j].ss,points[i].ff-points[j].ss);
				mp[slope]++;
			}
		}
		for(auto v:mp){
			maxAns=max(maxAns,same+v.ss);
		}

	}
	cout<<maxAns<<nline;

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