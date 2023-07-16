#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	int data;
	node*next;
	Node(int a){
		this->data=data;
		next=NULL;
	}
};
void reverse(node*p){
	if(p->next==NULL){
		node*head=p;
		return;
	}
	reverse(p->next);
	p->next->next=p;
	p->next=NULL;
}
void solve(){

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