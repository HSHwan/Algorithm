#include <iostream>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101
#define INF 1e9

using namespace std;

int cityNum, cost[MAX][MAX];

void solveAllTravelCost() {
    for (int k = 1; k <= cityNum; k++) {
        for (int i = 1; i <= cityNum; i++) {
            for (int j = 1; j <= cityNum; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

void printCostTable() {
    for (int i = 1; i <= cityNum; i++) {
        for (int j = 1; j <= cityNum; j++) {
            cout << (cost[i][j] != INF ? cost[i][j] : 0) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    FAST_IO
    int busNum;
    cin >> cityNum >> busNum;
    fill(&cost[1][1], &cost[cityNum][cityNum + 1], INF);
    for (int i = 0; i < busNum; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }
    for (int i = 1; i <= cityNum; i++)  cost[i][i] = 0;

    solveAllTravelCost();
    printCostTable();
}