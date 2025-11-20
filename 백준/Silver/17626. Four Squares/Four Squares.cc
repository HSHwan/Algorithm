#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 4);

    dp[0] = 0;
    for (int i = 1; i * i <= n; i++) {
        dp[i * i] = 1;
        for (int j = 1; j <= i && i * i + j * j <= n; j++) {
            dp[i * i + j * j] = min(dp[i * i + j * j], 2);
            for (int k = 1; k <= j && i * i + j * j + k * k <= n; k++) {
                dp[i * i + j * j + k * k] = min(dp[i * i + j * j + k * k], 3);
            }
        }
    }

    cout << dp[n];
}