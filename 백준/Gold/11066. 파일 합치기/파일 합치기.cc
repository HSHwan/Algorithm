#include <iostream>

#define MAX 501
#define INF 1e9
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int sum[MAX];
int dp[MAX][MAX];

int main() {
    FAST_IO
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int file;
            cin >> file;
            sum[i] = sum[i - 1] + file;
        }

        for (int len = 1; len < k; len++) {
            for (int i = 1; i <= k - len; i++) {
                int j = i + len;
                dp[i][j] = INF;

                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][k] << '\n';
    }
}