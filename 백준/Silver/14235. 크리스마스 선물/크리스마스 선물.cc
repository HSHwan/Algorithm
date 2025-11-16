#include <iostream>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    priority_queue<int> gifts;
    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        if (!a) {
            if (gifts.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << gifts.top() << '\n';
            gifts.pop();
        }
        else {
            while (a--) {
                int value;
                cin >> value;
                gifts.push(value);
            }
        }
    }
}