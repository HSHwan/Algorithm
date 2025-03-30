#include <iostream>
#include <vector>

using namespace std;

int row, column;
long long maxSumMul = 0;
vector<vector<int>> rectangle;
vector<int> rectangleIdx(1, 0);
vector<bool> visitedRow, visitedColumn;

void divideColumn(int recNum, int nowCol, int endCol, long long addMul) {
    if (rectangleIdx.size() == recNum) {
        rectangleIdx.push_back(row);

        long long mul = 1, sum;
        for (int i = 0; i < recNum; i++) {
            sum = 0;
            for (int j = rectangleIdx[i]; j < rectangleIdx[i + 1]; j++) {
                for (int k = nowCol; k < endCol; k++) {
                    sum += rectangle[j][k];
                }
            }
            mul *= sum;
        }
        mul *= addMul;
        
        maxSumMul = max(mul, maxSumMul);
        rectangleIdx.pop_back();
        return;
    }

    for (int i = rectangleIdx.back() + 1; i < row; i++) {
        if (visitedRow[i])
            continue;
        visitedRow[i] = true;
        rectangleIdx.push_back(i);
        divideColumn(recNum, nowCol, endCol, addMul);
        rectangleIdx.pop_back();
        visitedRow[i] = false;
    }
}

void divideRow(int recNum, int nowRow, int endRow, long long addMul) {
    if (rectangleIdx.size() == recNum) {
        rectangleIdx.push_back(column);

        long long mul = 1, sum;
        for (int i = 0; i < recNum; i++) {
            sum = 0;
            for (int j = nowRow; j < endRow; j++) {
                for (int k = rectangleIdx[i]; k < rectangleIdx[i + 1]; k++) {
                    sum += rectangle[j][k];
                }
            }
            mul *= sum;
        }
        mul *= addMul;
        
        maxSumMul = max(mul, maxSumMul);
        rectangleIdx.pop_back();
        return;
    }

    for (int i = rectangleIdx.back() + 1; i < column; i++) {
        if (visitedColumn[i])
            continue;
        visitedColumn[i] = true;
        rectangleIdx.push_back(i);
        divideRow(recNum, nowRow, endRow, addMul);
        rectangleIdx.pop_back();
        visitedColumn[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> row >> column;

    rectangle.resize(row, vector<int>(column));
    for (int i = 0; i < row; i++) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < column; j++)
            rectangle[i][j] = rowStr[j] - '0';
    }
    
    visitedColumn.assign(column, false);
    visitedColumn[0] = true;   
    visitedRow.assign(row, false);
    visitedRow[0] = true;

    long long recSum, revRecSum;
    if (column >= 3) {
        recSum = 0, revRecSum = 0;
        divideRow(3, 0, row, 1);
    }
    
    if (row >= 3) {
        recSum = 0, revRecSum = 0;
        divideColumn(3, 0, column, 1);
    }

    recSum = 0, revRecSum = 0;
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < column; j++) {
            recSum += rectangle[i - 1][j];
            revRecSum += rectangle[row - i][j];
        }
        divideRow(2, i, row, recSum);
        divideRow(2, 0, row - i, revRecSum);
    }

    recSum = 0, revRecSum = 0;
    for (int i = 1; i < column; i++) {
        for (int j = 0; j < row; j++) {
            recSum += rectangle[j][i - 1];
            revRecSum += rectangle[j][column - i];
        }
        divideColumn(2, i, column, recSum);
        divideColumn(2, 0, column - i, revRecSum);
    }

    cout << maxSumMul;
}