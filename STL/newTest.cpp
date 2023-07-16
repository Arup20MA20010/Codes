#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
// *************************************************************************************************************************
const int MOD = 1e9 + 7;
// *************************************************************************************************************************
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
int mod_inv(int x) {return power(x, MOD - 2);}
int lcm(int x, int y) {int res = x / __gcd(x, y); return (res * y);}
// *************************************************************************************************************************
int arr[1100][1100];
int pref[1100][1100];
void solve(){
    int n, m, q;
    // cin>>n>>m>>q;
    n=1000;
    m=1000;
    q=3;
    cout<<n<<m<<q;
    cout<<"break point 1"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            
        }
    }
    
    pref[1][1]=arr[1][1];
    cout<<"break point 2"<<endl;
    for(int i=2; i<=m; i++){
        pref[1][i]=pref[1][i-1] + arr[1][i];
    }
    
    for(int i=2; i<=n; i++){
        pref[i][1]=pref[i-1][1] + arr[i][1];
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            pref[i][j]=arr[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    cout<<q<<"breakpoint 3"<<endl;

    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<"hellow"<<endl;
        if(x1==1 and y1==1)
            cout<<pref[x2][y2]<<"\n";
        else if(x1==1)
            cout<<sub(pref[x2][y2], pref[x2][y1-1])<<"\n";
        else if(y1==1)
            cout<<sub(pref[x2][y2], pref[x1-1][y2])<<"\n";
        else
            cout<<sub(sub(add(pref[x2][y2], pref[x1-1][y1-1]), pref[x1-1][y2]), pref[x2][y1-1])<<"\n";

    }    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cout<<"what the fuck"<<endl;
    solve();
    return 0;
}














