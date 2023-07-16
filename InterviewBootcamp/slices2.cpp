#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long findArithmeticSeq(int arr[], int n)
{
    map<int,set<int>>mp;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         mp[arr[i]-arr[j]].insert(i);
    //         mp[arr[i]-arr[j]].insert(j);
    //     }
    // }
    long long ans=0;
    // for(auto v:mp){
    //     int key=v.first;
    //     set<int>st=v.second;
    //     int sz=st.size();
    //     if(sz<3)continue;
    //     ans+=((1<<sz)-((sz*(sz-1))/2)-sz-1);
    // }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findArithmeticSeq(arr, n) << '\n';
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    return 0;
}