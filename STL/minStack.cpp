#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<pair<int,int>>st;
public:

    MinStack() {

    }

    void push(int x) {
        if(st.empty()){
            st.push({x,x});
            return;
        }
        int minSoFar=min(st.top().second,x);
        st.push({x,minSoFar});
    }

    void pop() {
        if(st.empty())return;
        st.pop();
    }

    int top() {
        if(st.empty())return -1;
        int ans=st.top().first;
        return ans;
    }

    int getMin() {
        if(st.empty())return -1;
        int ans=st.top().second;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        // else if(op == "pop") {
        //     s.pop();
        // }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}