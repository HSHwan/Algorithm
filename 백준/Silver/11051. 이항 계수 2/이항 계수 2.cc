#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1001
#define MOD 10007

using namespace std;

int n, k;
int comb[MAX][MAX];

int main() {
    FAST_IO
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    cout << comb[n][k];
}