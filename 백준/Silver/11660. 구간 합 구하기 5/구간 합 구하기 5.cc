#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1024

using namespace std;

int tableLen, sumCount;
int tableSum[MAX + 1][MAX + 1];

int main() {
    FAST_IO
    cin >> tableLen >> sumCount;

    for (int i = 1; i <= tableLen; i++) {
        for (int j = 1; j <= tableLen; j++) {
            cin >> tableSum[i][j];
            tableSum[i][j] += tableSum[i][j - 1] + tableSum[i - 1][j] - tableSum[i - 1][j - 1];
        }
    }

    while (sumCount--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << tableSum[x2][y2] - tableSum[x1 - 1][y2] - tableSum[x2][y1 - 1] + tableSum[x1 - 1][y1 - 1] << '\n';
    }
}