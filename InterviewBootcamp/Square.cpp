#include <bits/stdc++.h>
using namespace std;

bool isValidSquare(vector<vector<long long>> &v)
{
    set<pair<long long ,long long>>st;
    for(auto x:v){
        st.insert({x[0],x[1]});
    }
    if(st.size()!=4)return false;
    long long x[4];long long y[4];
    int i=0;
    for(auto v:st){
        x[i]=v.first;
        y[i]=v.second;
        i++;
    }
    bool Ok=1;
    if((y[0]-y[3])*(y[1]-y[2])!=-1LL*(x[0]-x[3])*(x[1]-x[2]))Ok=0;
    if((y[1]-y[0])*(y[3]-y[1])!=-1LL*(x[1]-x[0])*(x[3]-x[1]))Ok=0;
    if((y[2]-y[0])*(y[3]-y[2])!=-1LL*(x[2]-x[0])*(x[3]-x[2]))Ok=0;
    return Ok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector<vector<long long>> v(4, vector<long long>(2));
    for (int i = 0; i < 4; i++)
        cin >> v[i][0] >> v[i][1];
    cout << isValidSquare(v) << '\n';
    return 0;
}