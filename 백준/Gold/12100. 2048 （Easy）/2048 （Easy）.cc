#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int boardSize;
vector<vector<vector<int>>> newBoard[6];

vector<vector<int>> moveLeft(vector<vector<int>> nowBoard) {
    for (int i = 0; i < boardSize; i++) {
        int k = 0;
        for (int j = 1; j < boardSize; j++) {
            if (!nowBoard[i][j])    continue;
            if (!nowBoard[i][k]) {
                swap(nowBoard[i][k], nowBoard[i][j]);
                continue;
            }
            else if (nowBoard[i][k] == nowBoard[i][j]) {
                nowBoard[i][k] *= 2;
                nowBoard[i][j] = 0;
            }
            else if (k + 1 < j)   j--;
            k++;
        }
    }

    return nowBoard;
}

vector<vector<int>> moveRight(vector<vector<int>> nowBoard) {
    for (int i = 0; i < boardSize; i++) {
        int k = boardSize - 1;
        for (int j = k - 1; j >= 0; j--) {
            if (!nowBoard[i][j])    continue;
            if (!nowBoard[i][k]) {
                swap(nowBoard[i][k], nowBoard[i][j]);
                continue;
            }
            else if (nowBoard[i][k] == nowBoard[i][j]) {
                nowBoard[i][k] *= 2;
                nowBoard[i][j] = 0;
            }
            else if (k - 1 > j)    j++;
            k--;
        }
    }    

    return nowBoard;
}

vector<vector<int>> moveTop(vector<vector<int>> nowBoard) {
    for (int i = 0; i < boardSize; i++) {
        int k = 0;
        for (int j = 1; j < boardSize; j++) {
            if (!nowBoard[j][i])    continue;
            if (!nowBoard[k][i]) {
                swap(nowBoard[k][i], nowBoard[j][i]);
                continue;
            }   
            else if (nowBoard[k][i] == nowBoard[j][i]) {
                nowBoard[k][i] *= 2;
                nowBoard[j][i] = 0;
            }
            else if (k + 1 < j)    j--;
            k++;
        }
    }    
    return nowBoard;
}

vector<vector<int>> moveBottom(vector<vector<int>> nowBoard) {
    for (int i = 0; i < boardSize; i++) {
        int k = boardSize - 1;
        for (int j = k - 1; j >= 0; j--) {
            if (!nowBoard[j][i])    continue;
            if (!nowBoard[k][i]) {
                swap(nowBoard[k][i], nowBoard[j][i]);
                continue;
            } 
            else if (nowBoard[k][i] == nowBoard[j][i]) {
                nowBoard[k][i] *= 2;
                nowBoard[j][i] = 0;
            }
            else if (k - 1 > j)    j++;
            k--;
        }
    }     

    return nowBoard;
}

void moveBoard(int moveCount) {
    for (int i = 0; i < moveCount; i++) {
        for (vector<vector<int>> b : newBoard[i]) {
            newBoard[i + 1].push_back(moveLeft(b));
            newBoard[i + 1].push_back(moveRight(b));
            newBoard[i + 1].push_back(moveTop(b));
            newBoard[i + 1].push_back(moveBottom(b));
        }
    }
}

int findMaxBlockNum(int moveCount) {
    int maxBlockNum = 0;
    for (vector<vector<int>> b : newBoard[moveCount]) {
        for (int i = 0; i < boardSize; i++) {
            maxBlockNum = max(*max_element(b[i].begin(), b[i].end()), maxBlockNum);
        }
    }
    return maxBlockNum;
}

int main() {
    FAST_IO
    cin >> boardSize;
    vector<vector<int>> board(boardSize, vector<int>(boardSize));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) cin >> board[i][j];
    }
    newBoard[0].push_back(board);

    moveBoard(5);
    cout << findMaxBlockNum(5);
}