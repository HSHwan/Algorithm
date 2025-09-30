#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n;
    cin >> n;
    vector<int> liquid(n);
    for (int i = 0; i < n; i++) cin >> liquid[i];

    sort(liquid.begin(), liquid.end());

    int start = 0, end = n - 1;
    pair<int, int> target = {INF, INF};
    while (start < end) {
        int sum = liquid[start] + liquid[end];
        if (abs(sum) < abs(target.first + target.second)) {
            target = {liquid[start], liquid[end]};
        }
        if (sum > 0)    end--;
        else    start++;
    }

    cout << target.first << ' ' << target.second;
}