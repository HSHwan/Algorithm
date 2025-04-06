#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100
#define X first.first
#define Y first.second
#define Z second

using namespace std;

typedef pair<pair<int, int>, int> xyz;

int row, col, boxNum;
int tomatoes[MAX][MAX][MAX];
vector<xyz> tomatoPos;

bool isOutOfRange(xyz pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col || pos.Z < 0 || pos.Z >= boxNum;
}

int findTimeAllTomatoesToRipen(int maxTomatoNum) {
    int time = 0;
    queue<pair<xyz, int>> tomatoQ;
    int ripenTomatoNum = 0;
    for (xyz pos : tomatoPos) {
        tomatoQ.push({pos, 0});
        ripenTomatoNum++;
    }
    if (ripenTomatoNum == maxTomatoNum) return 0;

    vector<xyz> dirs = {{{0, 1}, 0}, {{1, 0}, 0}, {{0, -1}, 0}, {{-1, 0}, 0}, {{0, 0}, 1}, {{0, 0}, -1}};
    while (!tomatoQ.empty()) {
        xyz nowPos = tomatoQ.front().first;
        int nowTime = tomatoQ.front().second;
        tomatoQ.pop();

        time = max(nowTime, time);

        for (xyz dir : dirs) {
            xyz nextPos = {{nowPos.X + dir.X, nowPos.Y + dir.Y}, nowPos.Z + dir.Z};
            if (isOutOfRange(nextPos))  continue;
            if (tomatoes[nextPos.X][nextPos.Y][nextPos.Z] == 0) {
                tomatoes[nextPos.X][nextPos.Y][nextPos.Z] = 1;
                ripenTomatoNum++;
                tomatoQ.push({nextPos, nowTime + 1});
            }
        }
    }

    if (ripenTomatoNum != maxTomatoNum)   return -1;
    return time;
}

int main() {
    FAST_IO
    cin >> col >> row >> boxNum;
    
    int maxTomatoNum = col * row * boxNum;
    for (int i = 0; i < boxNum; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cin >> tomatoes[j][k][i];
                if (tomatoes[j][k][i] == 1) tomatoPos.push_back({{j, k}, i});
                else if (tomatoes[j][k][i] == -1)   maxTomatoNum--;
            }
        }
    }

    cout << findTimeAllTomatoesToRipen(maxTomatoNum);
}