#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline '\n'
bool dp[100][100100];
bool computed[100][100100];
bool rec(vector<int>&arr,int level,int remSum){
    if(remSum<0)return false;
    if(level==arr.size()){
        return remSum==0;
    }
    if(computed[level][remSum])return dp[level][remSum];
    computed[level][remSum]=true;
    return dp[level][remSum]=rec(arr,level+1,remSum)|rec(arr,level+1,remSum-arr[level]);
}
void getIndices(vector<int>&arr,int level,int remSum,vector<int>&ans){
    if(level==arr.size())return;
    if(rec(arr,level+1,remSum)){
        getIndices(arr,level+1,remSum,ans);
    }else if(rec(arr,level+1,remSum-arr[level])){
        ans.push_back(level);
        getIndices(arr,level+1,remSum-arr[level],ans);
    }
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    vector<vector<int>>res;
    for(auto q:queries){
        vector<int>ans;
        getIndices(arr,0,q,ans);
        if(ans.empty()){
            res.push_back({-1});
            continue;
        }
        res.push_back(ans);
    }
    return res;
}
#undef nline

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);
    for(auto x:ans){
        for(auto v:x){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}