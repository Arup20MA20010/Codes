#include <bits/stdc++.h>
using namespace std;

int MinimumPlatforms(vector<pair<int, int>> &trains)
{
    // Complete the function
    vector<pair<int,int>>events;
    int cnt=0;
    for(auto train:trains){
        events.push_back({train.first,0});
        events.push_back({train.second,1});
    }
    sort(events.begin(),events.end());
    int maxCnt=0;
    int close=0;
    int open=0;
    for(int i=0;i<events.size();i++){
       if(open!=0&&open==close){
            close=0;
            maxCnt=max(maxCnt,open);
            open=0;
       }
       if(events[i].second){//ending event
            close++;

       }else{
            open++;
       }
    }
    return maxCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin >> n;

    vector<pair<int, int>> trains;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        trains.push_back({s, t});
    }

    cout << MinimumPlatforms(trains) << '\n';
}