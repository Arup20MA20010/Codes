#include <bits/stdc++.h>
using namespace std;

class FindPairswithSum
{
public:
    vector<int>A;
    vector<int>B;
    map<int,int>mp;
    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        this->A=A;
        this->B=B;
        for(auto x:B){
            mp[x]++;
        }
    }

    void add(int index, int val)
    {
        mp[B[index]]--;
        mp[B[index]+val]++;
        B[index]+=val;
    }

    int count(int total)
    {
        int ans=0;
        for(auto x:A){
            ans+=mp[total-x];
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}