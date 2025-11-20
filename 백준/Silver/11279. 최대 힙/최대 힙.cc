#include <iostream>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    priority_queue<int> pq;

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        
        if (x)  pq.push(x);
        else if (pq.empty()) cout << 0 << '\n';
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}