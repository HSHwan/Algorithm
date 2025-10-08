#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
#define OUT -1
#define CHEESE 1
#define EMPTY 0

using namespace std;

typedef pair<int, int> pii;

int row, col;
vector<vector<int>> board;
vector<pii> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

int dfs(vector<vector<int>>& b, vector<vector<bool>>& visited, int x, int y) {
    for (pii dir : dirs) {
        int nxt_x = x + dir.X, nxt_y = y + dir.Y;
        if (nxt_x >= row || nxt_x < 0 || nxt_y >= col || nxt_y < 0) return OUT;
        if (!visited[nxt_x][nxt_y] && b[nxt_x][nxt_y] == EMPTY) {
            visited[nxt_x][nxt_y] = true;
            if (dfs(b, visited, nxt_x, nxt_y) == OUT)  return OUT;
        }
    }
    return CHEESE;
}

int main() {
    FAST_IO
    cin >> row >> col;
    board.resize(row, vector<int>(col));
    int cheese_cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
            if (board[i][j] == CHEESE)  cheese_cnt++;
        }
    }

    int time = 0, end_cheese = 0;
    while (cheese_cnt) {
        time++;
        end_cheese = cheese_cnt;
        vector<vector<int>> saved_board = board;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (saved_board[i][j] == CHEESE) {
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    if (dfs(saved_board, visited, i, j) == OUT) {
                        board[i][j] = EMPTY;
                        cheese_cnt--;
                    }
                }
            }
        }
    }

    cout << time << '\n' << end_cheese;
}