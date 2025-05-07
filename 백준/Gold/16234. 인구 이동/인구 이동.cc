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

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= len || pos.Y < 0 || pos.Y >= len;
}

bool movePeople(pii start) {
    vector<pii> nations;
    queue<pii> posQ;
    posQ.push(start);
    visited[start.X][start.Y] = true;

    int sum = 0;
    while (!posQ.empty()) {
        pii nowPos = posQ.front();
        posQ.pop();

        nations.push_back(nowPos);
        sum += land[nowPos.X][nowPos.Y];

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isOutOfRange(nextPos) || visited[nextPos.X][nextPos.Y])   continue;
            int diff = abs(land[nowPos.X][nowPos.Y] - land[nextPos.X][nextPos.Y]);
            if (diff >= low && diff <= high) {
                visited[nextPos.X][nextPos.Y] = true;
                posQ.push(nextPos);
            }
        }
    }

    int unit = sum / nations.size();
    for (pii pos : nations) land[pos.X][pos.Y] = unit;
    
    return nations.size() >= 2;
}

bool move() {
    memset(visited, false, sizeof(visited));
    bool isMoved = false;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (visited[i][j])  continue;
            isMoved |= movePeople({i, j});
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
    while (move())  moveCount++;
    
    cout << moveCount;
}