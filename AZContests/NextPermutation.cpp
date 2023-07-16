#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
void solve(vector<int> &v)
{
	// Complete the function
    int n=v.size();
    int l=-1;
    for(int i=n-1;i>=1;i--){
        if(v[i-1]<v[i]){
            l=i-1;
            break;
        }
    }
    if(l==-1){
        sort(v.begin(),v.end());
        return;
    }
    int r=l+1;
    for(int j=l+1;j<n;j++){
        if(v[j]<=v[l]){
            r=j-1;
            break;
        }
    }
    swap(v[l],v[r]); 
    reverse(v.begin()+l+1,v.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	vector <int> v(n);
	for (auto &i : v)
		cin >> i;

	solve(v);

	for (auto i : v)
		cout << i << " ";
	cout << "\n";
}