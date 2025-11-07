#include <iostream>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int x;
        cin >> x;
        if (!x) {
            if (pq.empty()) cout << 0;
            else {
                cout << pq.top();
                pq.pop();
            }
            cout << '\n';
        }
        else    pq.push(x);
    }
}