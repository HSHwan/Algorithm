#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 50
#define INF 10e7
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int city[MAX][MAX];
int citySize, chickenNum;

vector<pii> house, chickenHouse;
vector<vector<int>> dist;

int solveDist(pii a, pii b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int findChickenMinSum() {
    int chickenDistMinSum = INF;
    int chickenHouseSize = chickenHouse.size();
    vector<int> select(chickenHouseSize, 0);
    fill_n(select.begin(), chickenNum, 1);
    do {
        int chickenDistSum = 0;
        for (int i = 0; i < house.size(); i++) {
            int chickenDist = INF;
            for (int j = 0; j < chickenHouseSize; j++) {
                if (!select[j]) continue;
                chickenDist = min(dist[i][j], chickenDist);
            }
            chickenDistSum += chickenDist;
        }
        chickenDistMinSum = min(chickenDistSum, chickenDistMinSum);
    } while (prev_permutation(select.begin(), select.end()));

    return chickenDistMinSum;
}

int main() {
    FAST_IO
    cin >> citySize >> chickenNum;
    for (int i = 0; i < citySize; i++) {
        for (int j = 0; j < citySize; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1)        house.push_back({i, j});
            else if (city[i][j] == 2)   chickenHouse.push_back({i, j});
        }
    }

    dist.resize(house.size(), vector<int>(chickenHouse.size()));
    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chickenHouse.size(); j++) {
            dist[i][j] = solveDist(house[i], chickenHouse[j]);
        }
    }
    int chickenDistSum = findChickenMinSum();
    cout << chickenDistSum;
}