#include <iostream>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101
#define INF 1e9

using namespace std;

int cityNum, cost[MAX][MAX][MAX];

void solveAllTravelCost() {
    for (int k = 1; k <= cityNum; k++) {
        for (int i = 1; i <= cityNum; i++) {
            for (int j = 1; j <= cityNum; j++) {
                cost[k][i][j] = min(cost[k - 1][i][j], cost[k - 1][i][k] + cost[k - 1][k][j]);
            }
        }
    }
}

void printCostTable() {
    for (int i = 1; i <= cityNum; i++) {
        for (int j = 1; j <= cityNum; j++) {
            cout << (cost[cityNum][i][j] != INF ? cost[cityNum][i][j] : 0) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    FAST_IO
    int busNum;
    cin >> cityNum >> busNum;
    fill(&cost[0][1][1], &cost[0][cityNum][cityNum + 1], INF);
    for (int i = 0; i < busNum; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[0][a][b] = min(cost[0][a][b], c);
    }
    for (int i = 1; i <= cityNum; i++)  cost[0][i][i] = 0;

    solveAllTravelCost();
    printCostTable();
}