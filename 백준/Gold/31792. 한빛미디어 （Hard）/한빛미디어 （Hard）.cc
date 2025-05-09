#include <iostream>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

multiset<int> books;

int calculatePages() {
    if (books.empty()) return 0;
    int pages = 0;
    auto it = books.begin();
    while (it != books.end()) {
        int min_price = *it;
        int max_price = 2 * min_price - 1;
        it = books.upper_bound(max_price);
        pages++;
    }
    return pages;
}

int main() {
    FAST_IO

    int q;
    cin >> q;

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd != 3) {
            int cost;
            cin >> cost;
            if (cmd == 1)   books.insert(cost);
            else if (cmd == 2) {
                auto it = books.find(cost);
                if (it != books.end())  books.erase(it);
            }
        }
        else    cout << calculatePages() << '\n';
    }
}