#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 15

using namespace std;

int queenNum;
bool col[MAX], leftDiag[2 * MAX], rightDiag[2 * MAX];
int nQueensNum = 0;

void findNQueenCase(int queen) {
    if (queen == queenNum) {
        nQueensNum++;
        return;
    }
    for (int i = 0; i < queenNum; i++) {
        if (col[i] || leftDiag[queen + i] || rightDiag[queenNum + queen - i])
            continue;
        col[i] = true;
        leftDiag[queen + i] = true;
        rightDiag[queenNum + queen - i] = true;
        findNQueenCase(queen + 1);
        col[i] = false;
        leftDiag[queen + i] = false;
        rightDiag[queenNum + queen - i] = false;
    }
}

int main() {
    FAST_IO
    cin >> queenNum;
    findNQueenCase(0);
    cout << nQueensNum;
}