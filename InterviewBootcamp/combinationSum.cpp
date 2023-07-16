#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

bool ifPossible(int n,int k){
    if(k<0)return false;
    if(n==0){
        if(k==0)return true;
        return false;
    }
    if(k==0)return true;
    return ifPossible(n-1,k)|ifPossible(n-1,k-n);
}
vector<vector<int>> combinationSum(int k, int n) {
    // write code here.
    
}























void checker() {
    int k, n;
    cin >> k >> n;
    vector<int> t;
    auto v = combinationSum(k, n);
    for (auto &x : v) {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}