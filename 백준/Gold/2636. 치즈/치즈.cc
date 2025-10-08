#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
#define CHEESE 1
#define EMPTY 0

using namespace std;

typedef pair<int, int> pii;

int row, col;
vector<vector<int>> board;
vector<pii> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
bool checked;

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
        vector<pii> target;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<pii> blank_q;

        blank_q.push({0, 0});
        visited[0][0] = true;

        while (!blank_q.empty()) {
            pii cur = blank_q.front();
            blank_q.pop();

            for (pii dir : dirs) {
                int nxt_x = cur.X + dir.X, nxt_y = cur.Y + dir.Y;
                if (nxt_x >= row || nxt_x < 0 || nxt_y >= col || nxt_y < 0 || visited[nxt_x][nxt_y])    continue;
                visited[nxt_x][nxt_y] = true;
                if (board[nxt_x][nxt_y] == CHEESE)  target.push_back({nxt_x, nxt_y});
                else    blank_q.push({nxt_x, nxt_y});
            }
        }
        for (pii t : target) {
            board[t.X][t.Y] = EMPTY;
        }
        cheese_cnt -= target.size();
    }

    cout << time << '\n' << end_cheese;
}