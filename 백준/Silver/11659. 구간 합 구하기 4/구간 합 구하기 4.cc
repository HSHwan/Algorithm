#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int n, m;

    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << '\n';
    }
}