#include <iostream>
#include <vector>
#include <cstring>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 300
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, col, map[MAX][MAX];
bool visited[MAX][MAX];
int iceCount;
pii dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

int dfs(pii pos) {
    int count = 1;
    for (pii dir : dirs) {
        pii nextPos = {pos.X + dir.X, pos.Y + dir.Y};
        if (isOutOfRange(nextPos) || !map[nextPos.X][nextPos.Y] || visited[nextPos.X][nextPos.Y])  continue;
        visited[nextPos.X][nextPos.Y] = true;
        count += dfs(nextPos);
    }

    return count;
}

int findOneIceSize(pii pos) {
    if (!map[pos.X][pos.Y]) return 0;

    memset(visited, false, sizeof(visited));
    visited[pos.X][pos.Y] = true;
    return dfs(pos);
}

int solveIceDivTime() {
    int t = 0;

    while (iceCount) {
        int past[row][col];
        pii lastIcePos;
        for (int i = 0; i < row; i++)   copy(&map[i][0], &map[i][0] + col, &past[i][0]);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!map[i][j]) continue;
                for (pii dir : dirs) {
                    pii adjPos = {i + dir.X, j + dir.Y};
                    if (isOutOfRange(adjPos) || past[adjPos.X][adjPos.Y])   continue;
                    map[i][j]--;
                }
                if (map[i][j] <= 0) {
                    map[i][j] = 0;
                    iceCount--;
                }
                else    lastIcePos = {i, j};
            }
        }
        t++;

        if (iceCount != findOneIceSize(lastIcePos))  return t;
    }

    return 0;
}

int main() {
    FAST_IO
    cin >> row >> col;

    iceCount = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
            if (map[i][j])  iceCount++;
        }
    }

    cout << solveIceDivTime();
}