#include <iostream>
#include <vector>
#include <cmath>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int testcase, x, y;
    cin >> testcase;

    while (testcase--) {
        cin >> x >> y;
        int dist = y - x;
        int step = sqrt(dist), rest = dist - step * step;
        cout << 2 * step - 1 + (rest / step) + !!(rest % step) << '\n';
    }

}