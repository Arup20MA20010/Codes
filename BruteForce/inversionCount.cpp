#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
int merge(int l,int r){
	int invCount=0;
	vector<int>temp;
	int mid=(l+r)/2;
	int i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}else{
			temp.push_back(arr[j]);
			j++;
			invCount+=(mid+1-i);
		}
	}
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=r){
		temp.push_back(arr[j]);
		j++;
	}
	i=l;
	for(auto v:temp){
		arr[i++]=v;
	}
	return invCount;
}
int mergeSort(int l,int r){
	if(l>=r)return 0;
	int InvCount=0;
	int mid=(l+r)/2;
	InvCount+=mergeSort(l,mid);
	InvCount+=mergeSort(mid+1,r);
	InvCount+=merge(l,r);
	return InvCount;
}
void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int cnt=mergeSort(0,n-1);
	cout<<(cnt&1)<<nline;
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