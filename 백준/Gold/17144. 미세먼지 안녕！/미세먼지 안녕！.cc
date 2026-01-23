#include <iostream>
#include <vector>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int houseRow, houseColumn;
int workTime;
vector<vector<int>> houseDust;
vector<int> airCleaner;

void input(){
    cin >> houseRow >> houseColumn >> workTime;
    vector<vector<int>>(houseRow, vector<int>(houseColumn)).swap(houseDust);

    FOR(i, houseRow){
        FOR(j, houseColumn){
            cin >> houseDust[i][j];
            if (houseDust[i][j] == -1)
                airCleaner.push_back(i);
        }
    }
}

bool isSpreadable(const pair<int, int>& pos){
    if (pos.X >= houseRow || pos.Y >= houseColumn || pos.X < 0 || pos.Y < 0)
        return false;
    return houseDust[pos.X][pos.Y] != -1;
}

void spreadDust(vector<vector<int>>& map, const pair<int, int>& pos, const int& posDust){
    vector<pair<int, int>> spreadDir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int spreadCount = 0;
    int spreadDustNum = posDust / 5;

    FOR(i, 4){
        pair<int, int> nextPos = {pos.X + spreadDir[i].X, pos.Y + spreadDir[i].Y};
        if (isSpreadable(nextPos)){
            map[nextPos.X][nextPos.Y] += spreadDustNum;
            spreadCount++;
        }
    }
    map[pos.X][pos.Y] += posDust - spreadCount * spreadDustNum;
}

void spreadDustAll(){
    vector<vector<int>> dustSpreaded(houseRow, vector<int>(houseColumn, 0));
    dustSpreaded[airCleaner[0]][0] = -1;
    dustSpreaded[airCleaner[1]][0] = -1;
    FOR(i, houseRow){
        FOR(j, houseColumn){
            if (houseDust[i][j] == -1 || !houseDust[i][j])
                continue;
            spreadDust(dustSpreaded, {i, j}, houseDust[i][j]);
        }
    }
    houseDust = dustSpreaded;
}

void workAirCleaner(){
    // Circulate counterclockwise
    for (int i = airCleaner[0] - 1; i > 0; i--)
        houseDust[i][0] = houseDust[i - 1][0];
    FOR(i, houseColumn - 1)
        houseDust[0][i] = houseDust[0][i + 1];
    FOR(i, airCleaner[0])
        houseDust[i][houseColumn - 1] = houseDust[i + 1][houseColumn - 1];
    for (int i = houseColumn - 1; i > 1; i--)
        houseDust[airCleaner[0]][i] = houseDust[airCleaner[0]][i - 1];
    houseDust[airCleaner[0]][1] = 0;

    // Circulate clockwise
    for (int i = airCleaner[1] + 1; i < houseRow - 1; i++)
        houseDust[i][0] = houseDust[i + 1][0];
    FOR(i, houseColumn - 1)
        houseDust[houseRow - 1][i] = houseDust[houseRow - 1][i + 1];
    for (int i = houseRow - 1; i > airCleaner[1]; i--)
        houseDust[i][houseColumn - 1] = houseDust[i - 1][houseColumn - 1];
    for (int i = houseColumn - 1; i > 1; i--)
        houseDust[airCleaner[1]][i] = houseDust[airCleaner[1]][i - 1];
    houseDust[airCleaner[1]][1] = 0;
}

void solve(){
    FOR(i, workTime){
        spreadDustAll();
        workAirCleaner();
    }
}

void output(){
    int dustSum = 0;

    FOR(i, houseRow){
        FOR(j, houseColumn){
            if (houseDust[i][j] != -1)
                dustSum += houseDust[i][j];
        }
    }
    cout << dustSum;
}

int main(){
    input ();
    solve ();
    output();
}