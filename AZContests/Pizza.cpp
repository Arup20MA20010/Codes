#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct Point{
	long double x,y;
	Point(long double x,long double y){
		this->x=x;
		this->y=y;
	}
};
void solve(){
	int v;cin>>v;
	int N;cin>>N;
	vector<Point>points;
	for(int i=0;i<N;i++){
		long double x,y;
		cin>>x>>y;
		points.push_back(Point(x,y));
	}
	long double maxDist=0.0;
	for(int i=0;i<points.size();i++){
		for(int j=i+1;j<points.size();j++){
			long double dist=sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x)+(points[i].y-points[j].y)*(points[i].y-points[j].y));
			maxDist=max(maxDist,dist);
		}
	}
	long double ans=maxDist/v;
	cout<<fixed<<setprecision(6)<<ans<<nline;
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