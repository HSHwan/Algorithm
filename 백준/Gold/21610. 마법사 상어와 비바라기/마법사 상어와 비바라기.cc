#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int sizeLen, moveCount;
vector<pair<int, int>> moveDir = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
vector<vector<int>> waterBaskets;
vector<pair<int, int>> clouds;
vector<vector<bool>> cloudPos;
vector<vector<int>> moves;

void input(){
    cin >> sizeLen >> moveCount;
    vector<vector<int>>(sizeLen, vector<int>(sizeLen, 0)).swap(waterBaskets);
    FOR(i, sizeLen){
        FOR(j, sizeLen){
            cin >> waterBaskets[i][j];
        }
    }
    vector<vector<int>>(moveCount, vector<int>(2)).swap(moves);
    FOR(i, moveCount){
        cin >> moves[i][0] >> moves[i][1];
    }
}

void moveClouds(const int& dir, const int& moveLen){
    for (pair<int, int>& cloud : clouds){
        cloud = {cloud.X + moveDir[dir].X * moveLen, cloud.Y + moveDir[dir].Y * moveLen};
        cloud.X %= sizeLen;
        cloud.Y %= sizeLen;
        cloud.X += cloud.X < 0 ? sizeLen : 0;
        cloud.Y += cloud.Y < 0 ? sizeLen : 0;
        cloudPos[cloud.X][cloud.Y] = true;
    }
}

void rainOnBaskets(){
    for (const pair<int, int>& cloud : clouds){
        waterBaskets[cloud.X][cloud.Y]++;
    }
}

bool isWithinRangeOfBaskets(const pair<int, int>& basket){
    return basket.X >= 0 && basket.X < sizeLen && basket.Y >= 0 && basket.Y < sizeLen;
}

void castWaterBugMagic(){
    vector<pair<int, int>> diagonalDir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (const pair<int, int>& cloud : clouds){
        FOR(i, 4){
            pair<int, int> aroundBasket = {cloud.X + diagonalDir[i].X, cloud.Y + diagonalDir[i].Y};
            if (isWithinRangeOfBaskets(aroundBasket) && waterBaskets[aroundBasket.X][aroundBasket.Y]){
                waterBaskets[cloud.X][cloud.Y]++;
            }
        }
    }
}

void generateClouds(){
    clouds.clear();
    FOR(i, sizeLen){
        FOR(j, sizeLen){
            if (waterBaskets[i][j] >= 2 && !cloudPos[i][j]){
                waterBaskets[i][j] -= 2;
                clouds.push_back({i, j});
            }
        }
    }
    vector<vector<bool>>(sizeLen, vector<bool>(sizeLen, false)).swap(cloudPos);
}

void solve(){
    clouds = {{sizeLen - 1, 0}, {sizeLen - 1, 1}, {sizeLen - 2, 0}, {sizeLen - 2, 1}};
    vector<vector<bool>>(sizeLen, vector<bool>(sizeLen, false)).swap(cloudPos);
    FOR(i, moveCount){
        moveClouds(moves[i][0], moves[i][1]);
        rainOnBaskets();
        castWaterBugMagic();
        generateClouds();
    }
}

void output(){
    int waterAmountSum = 0;
    for (const vector<int>& basket : waterBaskets){
        for (const int& water : basket)
            waterAmountSum += water;
    }
    cout << waterAmountSum;
}

int main(){
    input ();
    solve ();
    output();
}