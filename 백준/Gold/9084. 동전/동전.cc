#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        int m;
        cin >> m;
        
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[m] << '\n';
    }

}