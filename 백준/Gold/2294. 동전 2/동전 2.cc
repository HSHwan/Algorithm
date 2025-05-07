#include <iostream>
#include <vector>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int coinNum, costSum;
set<int> coins;

int main() {
    FAST_IO

    cin >> coinNum >> costSum;
    for (int i = 0; i < coinNum; i++) {
        int cost;
        cin >> cost;
        if (cost > costSum) continue;
        coins.insert(cost);
    }

    vector<int> dp(costSum + 1, costSum + 1);
    dp[0] = 0;
    for (int i = 1; i <= costSum; i++) {
        for (int j : coins) {
            if (j > i)  break;
            dp[i] = min(dp[i - j] + 1, dp[i]);
        }
    }

    if (dp[costSum] == costSum + 1) cout << -1;
    else                            cout << dp[costSum];
}