#include<bits/stdc++.h>
using namespace std;
string maxRoomBooked(vector<string> arr, int n) {
    // Write your code here.
    map<string,int>mp;
    for(int i=0;i<n;i++){
        char firstChar=arr[i][0];
        if(firstChar=='+'){
            mp[arr[i].substr(1)]++;
        }
    }
    int maxVal=0;
    string ans;
    for(auto v:mp){
        string key=v.first;
        if(maxVal<mp[key]){
            ans=key;
            maxVal=mp[key];
        }
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector<string>arr={"+1e8","+1e8"};
    cout<<maxRoomBooked(arr,2)<<endl;
    return 0;
}
