#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1000
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, col;
char map[MAX + 1][MAX + 1];
int dist[MAX][MAX][2];

struct Path {
    pii pos;
    int wallCount;
};

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

int findShortestPathLen(pii pos) {
    queue<Path> pathQ;
    pathQ.push({pos, 0});
    dist[pos.X][pos.Y][0] = 1;
    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!pathQ.empty()) {
        Path nowPath = pathQ.front();
        pii nowPos = nowPath.pos;
        pathQ.pop();

        if (nowPos.X == row - 1 && nowPos.Y == col - 1) {
            return dist[nowPos.X][nowPos.Y][nowPath.wallCount];
        }

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isOutOfRange(nextPos))  continue;
            if (map[nextPos.X][nextPos.Y] == '1' && nowPath.wallCount == 0) {
                dist[nextPos.X][nextPos.Y][1] = dist[nowPos.X][nowPos.Y][0] + 1;
                pathQ.push({nextPos, 1});
            }
            else if (map[nextPos.X][nextPos.Y] == '0' && !dist[nextPos.X][nextPos.Y][nowPath.wallCount]) {
                dist[nextPos.X][nextPos.Y][nowPath.wallCount] = dist[nowPos.X][nowPos.Y][nowPath.wallCount] + 1;
                pathQ.push({nextPos, nowPath.wallCount});
            }
        }
    }

    return -1;
}

int main() {
    FAST_IO
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        cin >> map[i];
    int pathLen = findShortestPathLen({0, 0});
    cout << pathLen;
}