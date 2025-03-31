#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 20
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, column;
char board[MAX + 1][MAX + 1];
bool visited[26];
int moveCount = 0;
pii dirs[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= column;
}

void dfs(pii pos, int count) {
    moveCount = max(count, moveCount);
    for (pii dir : dirs) {
        pii nextPos = {pos.X + dir.X, pos.Y + dir.Y};
        if (isOutOfRange(nextPos) || visited[board[nextPos.X][nextPos.Y] - 'A'])   continue;
        visited[board[nextPos.X][nextPos.Y] - 'A'] = true;
        dfs(nextPos, count + 1);
        visited[board[nextPos.X][nextPos.Y] - 'A'] = false;
    }
}

int main() {
    FAST_IO
    cin >> row >> column;
    for (int i = 0; i < row; i++)
        cin >> board[i];
    visited[board[0][0] - 'A'] = true;
    dfs({0, 0}, 1);
    cout << moveCount;
}