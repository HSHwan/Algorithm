#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

typedef pair<int, int> pii;

int labRow, labColumn;
int maxSafeAreaCount = 0, safeAreaCount;
vector<vector<int>> lab, newLab;
vector<pii> emptyPos, virusPos;

void input(){
    cin >> labRow >> labColumn;

    lab = vector<vector<int>>(labRow, vector<int>(labColumn));

    FOR(i, labRow) {
        FOR(j, labColumn) {
            cin >> lab[i][j];
            if (!lab[i][j]) {
                emptyPos.push_back({i, j});
            } else if (lab[i][j] == 2) {
                virusPos.push_back({i, j});
            }
        }
    }
}

bool isInfectious(pii pos) {
    if (pos.X >= labRow || pos.Y >= labColumn || pos.X < 0 || pos.Y < 0)
        return false;
    return !newLab[pos.X][pos.Y];
}

void infectVirus() {
    queue<pii> posQ;
    for (pii pos : virusPos) {
        posQ.push(pos);
    }

    pii nowPos, nextPos;
    vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();

        for (pii dir : dirs) {
            nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isInfectious(nextPos)) {
                newLab[nextPos.X][nextPos.Y] = 2;
                safeAreaCount--;
                posQ.push(nextPos);
            }
        }
    }
}

void solve(){
    vector<bool> orders(emptyPos.size());
    FOR (i, 3) {
        orders[i] = true;
    }

    do {
        newLab = lab;
        safeAreaCount = emptyPos.size() - 3;
        FOR(i, emptyPos.size()) {
            if (orders[i]) {
                newLab[emptyPos[i].X][emptyPos[i].Y] = 1;
            }
        }
        infectVirus();
        maxSafeAreaCount = max(maxSafeAreaCount, safeAreaCount);
    } while (prev_permutation(orders.begin(), orders.end()));
}

void output(){
    cout << maxSafeAreaCount;
}

int main(){
    input ();
    solve ();
    output();
}