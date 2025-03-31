#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 20
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, column;
char board[MAX + 1][MAX + 1];

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= column;
}

int findMaxMove(pii pos) {
    int moveCount = 0;
    int nowMove = 0;
    nowMove |= 1 << (board[pos.X][pos.Y] - 'A');
    queue<pair<pii, int>> moveQ;
    moveQ.push({pos, nowMove});

    vector<pii> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    while (!moveQ.empty()) {
        pii nowPos = moveQ.front().first;
        nowMove = moveQ.front().second;
        moveQ.pop();
        int nowMoveCount = __builtin_popcount(nowMove); 
        moveCount = max(nowMoveCount, moveCount);

        if (moveCount == 26)    return moveCount;

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isOutOfRange(nextPos) || nowMove & (1 << (board[nextPos.X][nextPos.Y] - 'A')))  continue;
            int nextMove = nowMove;
            nextMove |= 1 << (board[nextPos.X][nextPos.Y] - 'A');
            moveQ.push({nextPos, nextMove});
        }
    }
    
    return moveCount;
}

int main() {
    FAST_IO
    cin >> row >> column;
    for (int i = 0; i < row; i++)
        cin >> board[i];

    int moveCount = findMaxMove({0, 0});
    cout << moveCount;
}