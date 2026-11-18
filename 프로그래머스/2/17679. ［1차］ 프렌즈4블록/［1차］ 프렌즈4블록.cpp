#include <string>
#include <vector>
#define DEL '-'
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int del_count = 0;
vector<string> cur_board;

void clear_board(vector<pii> target, int m, int n) {
    for (pii t : target) {
        del_count += cur_board[t.X][t.Y] != DEL;
        del_count += cur_board[t.X + 1][t.Y] != DEL;
        del_count += cur_board[t.X][t.Y + 1] != DEL;
        del_count += cur_board[t.X + 1][t.Y + 1] != DEL;
        cur_board[t.X][t.Y] = DEL;
        cur_board[t.X + 1][t.Y] = DEL;
        cur_board[t.X][t.Y + 1] = DEL;
        cur_board[t.X + 1][t.Y + 1] = DEL;
    }
    
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i > 0; i--) {
            if (cur_board[i][j] == DEL) {
                for (int k = i - 1; k >= 0; k--) {
                    if (cur_board[k][j] != DEL) {
                        cur_board[i][j] = cur_board[k][j];
                        cur_board[k][j] = DEL;
                        break;
                    }
                }
            }
        }
    }
}

bool is_deletable(int x, int y, int m, int n) {
    if (x >= 0 && x < m - 1 && y >= 0 && y < n - 1) {
        char cur_block = cur_board[x][y];
        if (cur_block == DEL)   return false;
        return cur_block == cur_board[x + 1][y] && cur_block == cur_board[x][y + 1] && cur_block == cur_board[x + 1][y + 1];
    }
    return false;
}

int solution(int m, int n, vector<string> board) {
    cur_board = board;
    bool deleted = true;
    while (deleted) {
        deleted = false;
        vector<pii> target;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (is_deletable(i, j, m, n)) {
                    target.push_back({i, j});
                    deleted = true;
                }    
            }
        }
        clear_board(target, m, n);
    }
    
    return del_count;
}