#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

struct Virus {
    pii pos;
    int time;
};

int row, col, infect, delay;
vector<string> map;
queue<Virus> virusQ, buildQ;

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

Virus getNextVirus() {
    if (virusQ.empty()) {
        Virus next = buildQ.front();
        buildQ.pop();
        return next;
    }

    if (buildQ.empty()) {
        Virus next = virusQ.front();
        virusQ.pop();
        return next;
    }

    int virusTime = virusQ.front().time, buildTime = buildQ.front().time;
    if (virusTime < buildTime) {
        Virus next = virusQ.front();
        virusQ.pop();
        return next;
    }
    else {
        Virus next = buildQ.front();
        buildQ.pop();
        return next;
    }
}

void solve(vector<pii> virus) {
    vector<vector<int>> visited(row, vector<int>(col));
    for (pii v : virus) {
        visited[v.X][v.Y] = 1;
        virusQ.push({v, 0});
    }
    pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!virusQ.empty() || !buildQ.empty()) {
        Virus now = getNextVirus();
        pii nowPos = now.pos;

        if (now.time > infect)  break;

        visited[nowPos.X][nowPos.Y] = 1;

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isOutOfRange(nextPos) || visited[nextPos.X][nextPos.Y]) continue;
            visited[nextPos.X][nextPos.Y] = -1;
            Virus next = {nextPos, now.time + 1};
            if (map[nextPos.X][nextPos.Y] == '#') {
                next.time += delay;
                buildQ.push(next);
            }
            else    virusQ.push(next);
            
        }
    }

    bool isSafe = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] != 1) {
                cout << i + 1 << ' ' << j + 1 << '\n';   
                isSafe = true;
            }  
        }
    }

    if (!isSafe)    cout << -1;
}

int main() {
    FAST_IO
    cin >> row >> col;

    int virusNum, buildNum;
    cin >> infect >> delay >> virusNum >> buildNum;

    vector<pii> firstVirus;
    map.resize(row);
    for (int i = 0; i < row; i++) {
        cin >> map[i];
        for (int j = 0; j < col; j++) {
            if (map[i][j] == '*')   firstVirus.push_back({i, j});
        }
    }  

    solve(firstVirus);
}