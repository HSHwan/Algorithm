#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, column;
char maze[MAX + 1][MAX + 1];

bool isInMaze(pii pos) {
    return pos.X >= 0 && pos.X < row && pos.Y >= 0 && pos.Y < column;
}

int findWallMinNum(pii pos) {
    vector<vector<int>> wallCheck(row, vector<int>(column, row * column));
    pii nowPos;
    queue<pii> posQ;
    posQ.push(pos);
    wallCheck[pos.X][pos.Y] = 0;

    vector<pii> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    while (!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (!isInMaze(nextPos)) continue;
            int nextWallCount = wallCheck[nowPos.X][nowPos.Y] + (maze[nextPos.X][nextPos.Y] - '0');
            if (nextWallCount < wallCheck[nextPos.X][nextPos.Y]) {
                wallCheck[nextPos.X][nextPos.Y] = nextWallCount;
                posQ.push(nextPos);
            }
        }
    }

    return wallCheck[row - 1][column - 1];
}

int main() {
    FAST_IO
    cin >> column >> row;
    for (int i = 0; i < row; i++)
        cin >> maze[i];

    int wallCount = findWallMinNum({0, 0});
    cout << wallCount;
}