#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 50
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int len, low, high;
int land[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pii> nations;
int sum = 0;
bool isMoved;

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= len || pos.Y < 0 || pos.Y >= len;
}

void dfs(pii pos) {
    visited[pos.X][pos.Y] = true;
    sum += land[pos.X][pos.Y];
    nations.push_back(pos);
    for (pii dir : dirs) {
        pii nextPos = {pos.X + dir.X, pos.Y + dir.Y};
        if (isOutOfRange(nextPos) || visited[nextPos.X][nextPos.Y]) continue;
        int diff = abs(land[pos.X][pos.Y] - land[nextPos.X][nextPos.Y]);
        if (diff >= low && diff <= high)    dfs(nextPos);
    }

    if (nations.size() > 1 && pos == nations[0]) {
        sum /= nations.size();
        for (pii nation : nations)  land[nation.X][nation.Y] = sum;
        isMoved = true;
    }
}

bool move() {
    memset(visited, false, sizeof(visited));
    isMoved = false;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (visited[i][j])  continue;
            dfs({i, j});
            sum = 0;
            nations.clear();
        }
    }

    return isMoved;
}

int main() {
    FAST_IO
    cin >> len >> low >> high;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++)   cin >> land[i][j];
    }

    int moveCount = 0;
    while (true) {
        move();
        if (isMoved)    moveCount++;
        else    break;
    }
    
    cout << moveCount;
}