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

    vector<vector<int>> color_cost;

    int n;
    cin >> n;

    color_cost.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color_cost[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, INF)));
    dp[0][R][R] = color_cost[0][R];
    dp[0][G][G] = color_cost[0][G];
    dp[0][B][B] = color_cost[0][B];

    dp[1][R][G] = color_cost[1][R] + dp[0][G][G];
    dp[1][R][B] = color_cost[1][R] + dp[0][B][B];
    dp[1][G][R] = color_cost[1][G] + dp[0][R][R];
    dp[1][G][B] = color_cost[1][G] + dp[0][B][B];
    dp[1][B][R] = color_cost[1][B] + dp[0][R][R];
    dp[1][B][G] = color_cost[1][B] + dp[0][G][G];

    for (int i = 2; i < n - 1; i++) {
        for (int k = 0; k < 3; k++) {
            dp[i][R][k] = min(dp[i - 1][G][k], dp[i - 1][B][k]) + color_cost[i][R];
            dp[i][G][k] = min(dp[i - 1][R][k], dp[i - 1][B][k]) + color_cost[i][G];
            dp[i][B][k] = min(dp[i - 1][R][k], dp[i - 1][G][k]) + color_cost[i][B];
        }
    }

    dp[n - 1][R][G] = min(dp[n - 2][G][G], dp[n - 2][B][G]) + color_cost[n - 1][R];
    dp[n - 1][R][B] = min(dp[n - 2][B][B], dp[n - 2][G][B]) + color_cost[n - 1][R];
    dp[n - 1][G][R] = min(dp[n - 2][R][R], dp[n - 2][B][R]) + color_cost[n - 1][G];
    dp[n - 1][G][B] = min(dp[n - 2][B][B], dp[n - 2][R][B]) + color_cost[n - 1][G];
    dp[n - 1][B][R] = min(dp[n - 2][G][R], dp[n - 2][R][R]) + color_cost[n - 1][B];
    dp[n - 1][B][G] = min(dp[n - 2][R][G], dp[n - 2][G][G]) + color_cost[n - 1][B];

    int min_cost = min(min(min(dp[n - 1][R][G], dp[n - 1][R][B]), min(dp[n - 1][G][R], dp[n - 1][G][B])), min(dp[n - 1][B][R], dp[n - 1][B][G]));
    cout << min_cost;
}