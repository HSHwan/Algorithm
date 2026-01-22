#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101

using namespace std;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    vector<int> ladder(MAX, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    vector<int> snake(MAX, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    vector<int> board(MAX, 2 * MAX);

    board[1] = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < MAX; i++) {
            for (int j = 1; j <= 6; j++) {
                int nxt = i + j;
                if (nxt >= MAX)   break;
                if (ladder[nxt]) {
                    board[ladder[nxt]] = min(board[ladder[nxt]], board[i] + 1);
                }
                else if (snake[nxt]) {
                    board[snake[nxt]] = min(board[snake[nxt]], board[i] + 1);
                }
                else {
                    board[nxt] = min(board[nxt], board[i] + 1);
                }
            }
        }
    }

    cout << board[100];
}