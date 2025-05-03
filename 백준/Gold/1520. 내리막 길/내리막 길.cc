#include <iostream>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 500
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, col;
int map[MAX][MAX], visited[MAX][MAX];
pii dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isMovable(pii pos) {
    return pos.X >= 0 && pos.X < row && pos.Y >= 0 && pos.Y < col;
}

int bfs(pii start) {
    queue<pii> posQ;
    visited[start.X][start.Y] = 1;
    posQ.push(start);

    while (!posQ.empty()) {
        pii nowPos = posQ.front();
        posQ.pop();

        if (nowPos.X == row - 1 && nowPos.Y == col - 1) continue;
        
        for (int i = 0; i < 4; i++) {
            pii nextPos = {nowPos.X + dir[i].X, nowPos.Y + dir[i].Y};
            if (isMovable(nextPos) && map[nowPos.X][nowPos.Y] > map[nextPos.X][nextPos.Y]) {
                if (!visited[nextPos.X][nextPos.Y]) posQ.push(nextPos);
                visited[nextPos.X][nextPos.Y] += visited[nowPos.X][nowPos.Y];
            }
        }
        visited[nowPos.X][nowPos.Y] = 0;
    }

    return visited[row - 1][col - 1];
}

int main() {
    FAST_IO
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs({0, 0});
}