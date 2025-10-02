#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> note1(n);
        for (int i = 0; i < n; i++) cin >> note1[i];

        sort(note1.begin(), note1.end());

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int note2;
            cin >> note2;
            cout << binary_search(note1.begin(), note1.end(), note2) << '\n';
        }
    }
}