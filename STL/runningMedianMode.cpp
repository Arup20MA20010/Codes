#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=1e9+7;
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	return gcd(b,a%b);
}
int rem(int a){
	return ((a%mod)+mod)%mod;
}
int mulMod(int a,int b){
	return (((a%mod)*(b%mod))%mod+mod)%mod;
}
int binPow(int a,int p){
	int ans=1;
	while(p){
		if(p&1){
			ans=mulMod(ans,a);
		}
		a=mulMod(a,a);
		p>>=1;
	}
	return ans;
}
int inverseMod(int a){
	return rem(binPow(a,mod-2));
}
int divideMod(int a,int b){
	return rem(mulMod(a,inverseMod(b)));
}
struct runningStats{
	multiset<int>small;
	multiset<int>large;
	int n;
	set<pair<int,int>>freq;
	map<int,int>mp;
	int sum;
	runningStats(){
		n=0;
		sum=0;
	}
	void reorganise(){
		//small size should always be=1/0 +size of large
		//if small has more elements than required
		int sz=small.size();int lz=large.size();
		if(sz==lz||sz==lz+1)return;
		while(sz-lz>1){
			auto it=small.rbegin();
			large.insert(*it);
			small.erase(small.find(*it));
			sz--;
			lz++;
		}
		//if large has more elemens than required
		while(lz>sz){
			auto it=large.begin();
			small.insert(*it);
			large.erase(large.find(*it));
			lz--;
			sz++;
		}
	}
	void insert(int x){
		if(n==0)small.insert(x);
		if(*small.rbegin()>=x){
			small.insert(x);
		}else{
			large.insert(x);
		}
		n++;
		sum+=x;
		reorganise();
		if(mp.find(x)!=mp.end()){
			freq.erase({mp[x],-x});
			mp[x]++;
			freq.insert({mp[x],-x});
		}else{
			mp[x]=1;
			freq.insert({1,-x});
		}
	}
	void remove(int x){
		if(n==0)return;
		if(!small.empty()&&small.find(x)!=small.end()){
			small.erase(small.find(x));
		}else if(!large.empty()&&large.find(x)!=large.end()){
			large.erase(large.find(x));
		}else{
			return;
		}
		n--;
		reorganise();
		if(mp.find(x)!=mp.end()&&mp[x]>0){
			freq.erase({mp[x],-x});
			mp[x]--;
			if(mp[x]){
				freq.insert({mp[x],-x});
			}
			sum-=x;
		}
	}
	int getMode(){
		if(n==0)return -1;
		auto it=freq.rbegin();
		return -1*it->second;
	}
	int getMedian(){
		if(n==0)return -1;
		if(n&1){
			return *small.rbegin();
		}
		int x=*small.rbegin();
		int y=*large.begin();
		return divideMod((x+y)/gcd(x+y,2),2/gcd(x+y,2));
	}
	int getMean(){
		if(n==0)return -1;
		return divideMod(sum/gcd(sum,n),n/gcd(sum,n));
	}
};
void solve(){
	int q;cin>>q;
	runningStats rs;
	while(q--){
		string s;cin>>s;
		if(s=="insert"){
			int x;cin>>x;
			rs.insert(x);
		}else if(s=="remove"){
			int x;cin>>x;
			rs.remove(x);
		}else if(s=="getMean"){
			cout<<rs.getMean()<<nline;
		}else if(s=="getMedian"){
			cout<<rs.getMedian()<<nline;
		}else if(s=="getMode"){
			cout<<rs.getMode()<<nline;
		}
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