#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n, k;
    cin >> n >> k;

    vector<int> cats(n);
    for (int i = 0; i < n; i++) cin >> cats[i];

    sort(cats.begin(), cats.end());

    int count = 0;
    int start = 0, end = n - 1;
    for (int end = n - 1; start < end; end--) {
        int sum = cats[start] + cats[end];
        if (sum <= k) {
            count++;
            start++;
            continue;
        }
    }

    cout << count;
}