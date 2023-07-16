#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int n)
{
    queue<unsigned int>st;
    for(int i=0;i<32;i++){
        st.push((n>>i)&1);
    }
    unsigned int num=0;
    while(!st.empty()){
        num=num*2+st.front();
        st.pop();
    }
    return num;
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
    int t;
    cin >> t;
    while (t--)
    {
        unsigned int n;
        cin >> n;
        cout << reverseBits(n) << '\n';
    }
    return 0;
}