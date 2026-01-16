#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define R 0
#define G 1
#define B 2
#define INF 1e9

using namespace std;

int main() {
    FAST_IO
    int n;
    cin >> n;

    vector<vector<int>> color_cost(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> color_cost[i][R] >> color_cost[i][G] >> color_cost[i][B];
    }

    vector<vector<int>> dp(n, vector<int>(3));
    int min_cost = INF;
    for (int start = 0; start < 3; start++) {
        for (int i = 0; i < 3; i++) {
            if (i == start) dp[0][i] = color_cost[0][i];
            else    dp[0][i] = INF;
        }
        for (int i = 1; i < n; i++) {
            dp[i][R] = color_cost[i][R] + min(dp[i - 1][G], dp[i - 1][B]);
            dp[i][G] = color_cost[i][G] + min(dp[i - 1][R], dp[i - 1][B]);
            dp[i][B] = color_cost[i][B] + min(dp[i - 1][R], dp[i - 1][G]);
        }

        for (int i = 0; i < 3; i++) {
            if (i == start) continue;
            min_cost = min(min_cost, dp[n - 1][i]);
        }
    }
    
    cout << min_cost;
}