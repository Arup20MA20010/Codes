#include <bits/stdc++.h>

using namespace std;
int playlist(vector<int> &songs)
{
    //write code here
    
    int n=songs.size();
    map<int,int>mp;
    mp[0]=1;
    int maxSum=0;
    sort(songs.begin(),songs.end());
    maxSum=songs[n-1]+songs[n-2];
    for(int i=1;i<=(maxSum/60);i++){
        for(int k=0;k<n;k++){
            if(60*i>=songs[k]){
                mp[60*i-songs[k]]++;
            }
        }
        
    }
    int cnt=0;
    // for(int i=0;i<n;i++){
    //     if(songs[i]%30==0){
    //         mp[songs[i]]--;
    //     }
    // }
    
    // cout<<mp[30]<<endl;
    for(int i=0;i<n;i++){
        if(mp.find(songs[i])!=mp.end()){
            cnt+=mp[songs[i]];
            // mp[songs[i]]--;
            if((songs[i]%30)==0)cnt-=2;
            cout<<cnt<<endl;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    vector<int> songs(n);
    for(int i=0;i<n;++i)
    cin>>songs[i];
    cout<<playlist(songs); 
    return 0;
}