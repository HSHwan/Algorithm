#include <iostream>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_COST 1'000'001

using namespace std;

set<int> books;
int book_num[MAX_COST];

int calculatePages() {
    if (books.empty()) return 0;
    int pages = 0;
    auto it = books.begin();
    while (it != books.end()) {
        int min_price = *it;
        int max_price = 2 * min_price;
        it = books.lower_bound(max_price);
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
            if (cmd == 1) {
                if (!book_num[cost])    books.insert(cost);
                book_num[cost]++;
            }  
            else if (cmd == 2) {
                if (book_num[cost])     book_num[cost]--;
                if (!book_num[cost])    books.erase(cost);
            }  
        }
        else    cout << calculatePages() << '\n';
    }
}