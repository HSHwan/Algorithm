#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SUM 21
#define MAX_NUM 101
using namespace std;

typedef long long ll;

int n;
int arr[MAX_NUM];
ll dp[MAX_NUM][MAX_SUM];

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < MAX_SUM; j++) {
            if (dp[i - 1][j]) {
                if (j + arr[i] < MAX_SUM)   dp[i][j + arr[i]] += dp[i - 1][j];
                if (j - arr[i] >= 0)    dp[i][j - arr[i]] += dp[i - 1][j];   
            }
        }
    }

    cout << dp[n - 2][arr[n - 1]];
}