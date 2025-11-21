#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 16

using namespace std;

int path[3][MAX_SIZE][MAX_SIZE];

int main() {
    FAST_IO
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        if (map[0][i])  break;
        path[0][0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (map[i][j])  continue;
            path[0][i][j] = path[0][i][j - 1] + path[1][i][j - 1];
            path[2][i][j] = path[1][i - 1][j] + path[2][i - 1][j];
            if (map[i - 1][j] || map[i][j - 1]) continue;
            path[1][i][j] = path[0][i - 1][j - 1] + path[1][i - 1][j - 1] + path[2][i - 1][j - 1];
            
        }
    }

    cout << path[0][n - 1][n - 1] + path[1][n - 1][n - 1] + path[2][n - 1][n - 1];
}