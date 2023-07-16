#include <bits/stdc++.h>
using namespace std;


class CustomStack {
public:
	deque<int>dq;
    int capacity;
	CustomStack(int maxSize) {
        capacity=maxSize;
	}

	void push(int x) {
		if(dq.size()==capacity)return;
        dq.push_back(x);
	}

	int pop() {
        if(dq.empty())return -1;
        int x=dq.back();
        dq.pop_back();
        return x;
	}

	void increment(int k, int val) {
        for(int i=0;i<min(k,dq.size());i++){
            dq[i]+=val;
        }
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxSize;
	cin >> maxSize;

	int q;
	cin >> q;

	CustomStack* customStack = new CustomStack(maxSize);

	for (int itr = 0; itr < q; itr++) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;

			customStack->push(x);
		}
		else if (op == "pop") {
			cout << customStack->pop() << "\n";
		}
		else if (op == "inc") {
			int k, val;
			cin >> k >> val;
			customStack->increment(k, val);
		}
	}

}