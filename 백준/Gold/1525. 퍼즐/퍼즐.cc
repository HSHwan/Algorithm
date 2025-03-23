#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PUZZLE_SIZE 3
#define X first
#define Y second

typedef pair<int, int> pii;

bool isOutOfRange(pii idx) {
    return idx.X < 0 || idx.X >= PUZZLE_SIZE || idx.Y < 0 || idx.Y >= PUZZLE_SIZE;
}

int findOrganizedPuzzle(string start, string target) {
    queue<pair<string, int>> puzzleQ;
    set<string> visited;
    puzzleQ.push({start, 0});
    visited.insert(start);

    vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!puzzleQ.empty()) {
        string nowPuzzle = puzzleQ.front().first;
        int nowMoveCount = puzzleQ.front().second;
        puzzleQ.pop();

        if (nowPuzzle == target)
            return nowMoveCount;

        int zeroIdx = nowPuzzle.find('0');
        pii nowEmptyIdx = {zeroIdx / 3, zeroIdx % 3};
        
        for (pii dir : dirs) {
            pii nextEmptyIdx = {nowEmptyIdx.X + dir.X, nowEmptyIdx.Y + dir.Y};
            if (isOutOfRange(nextEmptyIdx))
                continue;
            string nextPuzzle = nowPuzzle;
            swap(nextPuzzle[3 * nowEmptyIdx.X + nowEmptyIdx.Y], nextPuzzle[3 * nextEmptyIdx.X + nextEmptyIdx.Y]);
            if (!visited.count(nextPuzzle)) {
                puzzleQ.push({nextPuzzle, nowMoveCount + 1});
                visited.insert(nextPuzzle);
            }
        }
    }

    return -1;
}

int main() {
    FAST_IO

    string start, target = "123456780";
    for (int i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++) {
        char num;
        cin >> num;
        start.push_back(num);
    }

    int moveCount = findOrganizedPuzzle(start, target);
    cout << moveCount;
}