#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101

using namespace std;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    int move_num = n + m;
    vector<int> move(MAX, 0);
    for (int i = 0; i < move_num; i++) {
        int x, y;
        cin >> x >> y;
        move[x] = y;
    }

    vector<int> board(MAX, 2 * MAX);

    board[1] = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < MAX; i++) {
            for (int j = 1; j <= 6; j++) {
                int nxt = i + j;
                if (nxt >= MAX)   break;
                if (move[nxt]) {
                    board[move[nxt]] = min(board[move[nxt]], board[i] + 1);
                }
                else {
                    board[nxt] = min(board[nxt], board[i] + 1);
                }
            }
        }
    }

    cout << board[100];
}