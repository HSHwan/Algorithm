#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SUDOKU_SIZE 9
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
vector<int> emptyCases[SUDOKU_SIZE][SUDOKU_SIZE];
vector<pii> emptyPos;

void checkSudokuNum(int* num, pii pos) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        num[sudoku[i][pos.Y]]++;
        num[sudoku[pos.X][i]]++;
    }
    pii basePos = {3 * (pos.X / 3), 3 * (pos.Y / 3)};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            num[sudoku[basePos.X + i][basePos.Y + j]]++;
        }
    }
}

void checkEmptyCases() {
    for (pii pos : emptyPos) {
        int num[10] = {0, };
        checkSudokuNum(num, pos);
        int minCount = *min_element(num + 1, num + 10);
        for (int i = 1; i <= 9; i++) {
            if (num[i] == minCount)
                emptyCases[pos.X][pos.Y].push_back(i);
        }
    }
}

bool isNotSudoku(pii pos) {
    int num[10] = {0, };
    checkSudokuNum(num, pos);
    int maxCount = *max_element(num + 1, num + 10);
    return maxCount > 3;
}

bool dfs(int idx) {
    if (idx == emptyPos.size()) return true;
    pii pos = emptyPos[idx];
    for (int nowNum : emptyCases[pos.X][pos.Y]) {
        sudoku[pos.X][pos.Y] = nowNum;
        if (isNotSudoku(pos))   continue;
        if (dfs(idx + 1))   return true;
    }
    sudoku[pos.X][pos.Y] = 0;
    return false;
}

void printSudoku() {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    FAST_IO
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            cin >> sudoku[i][j];
            if (!sudoku[i][j])
                emptyPos.push_back({i, j});
        }
    }
    checkEmptyCases();
    dfs(0);
    printSudoku();   
}