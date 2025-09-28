#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n;
    cin >> n;
    vector<int> board(3), min_board(3), max_board(3);
    for (int i = 0; i < n; i++) {
        cin >> board[0] >> board[1] >> board[2];
        max_board = {
            board[0] + max(max_board[0], max_board[1]),
            board[1] + max(max(max_board[0], max_board[1]), max_board[2]),
            board[2] + max(max_board[1], max_board[2])
        };
        min_board = {
            board[0] + min(min_board[0], min_board[1]),
            board[1] + min(min(min_board[0], min_board[1]), min_board[2]),
            board[2] + min(min_board[1], min_board[2])
        };
    } 

    cout << max(max(max_board[0], max_board[1]), max_board[2]) << ' ' <<
            min(min(min_board[0], min_board[1]), min_board[2]);
}