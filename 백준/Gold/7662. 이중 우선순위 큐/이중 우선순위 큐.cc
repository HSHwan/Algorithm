#include <iostream>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void solve() {
    int k;
    cin >> k;

    multiset<int> dual_pq;
    for (int i = 0; i < k; i++) {
        char cmd;
        int val;
        cin >> cmd >> val;
        if (cmd == 'I') dual_pq.insert(val);
        else if (!dual_pq.empty()){
            if (val == -1)  dual_pq.erase(dual_pq.begin());
            else            dual_pq.erase(--dual_pq.end());
        }
    }

    if (!dual_pq.empty())   cout << *(--dual_pq.end()) << ' ' <<  *dual_pq.begin() << '\n';
    else                    cout << "EMPTY\n";
}

int main() {
    FAST_IO
    int testcase;
    cin >> testcase;
    while (testcase--)  solve();
}