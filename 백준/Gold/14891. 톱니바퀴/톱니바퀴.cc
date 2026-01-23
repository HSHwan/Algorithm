#include <iostream>
#include <vector>
#include <deque>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<deque<int>> gears(5, deque<int>(8));
int turnNum;
vector<vector<int>> turnInfo; 

void input(){
    string gearInfo;
    FOR(i, 4){
        cin >> gearInfo;
        FOR (j, 8)
            gears[i + 1][j] = gearInfo[j] - '0';
    }

    cin >> turnNum;
    vector<vector<int>>(turnNum, vector<int>(2)).swap(turnInfo);
    FOR(i, turnNum)
        cin >> turnInfo[i][0] >> turnInfo[i][1];
}

void turnGear(const int& gearNum, const int& dir){
    if (dir == 1){
        gears[gearNum].push_front(gears[gearNum].back());
        gears[gearNum].pop_back();
    }
    else {
        gears[gearNum].push_back(gears[gearNum].front());
        gears[gearNum].pop_front();
    }
}

bool checkGearPole(const int& left, const int& right){
    return gears[left][2] != gears[right][6];
}

void solve(){
    vector<bool> gearCheck(3);
    vector<vector<int>> turnOrder = {{}, {0, 1, 2}, {1, 2}, {1, 0}, {2, 1, 0}};
    FOR(i, turnNum){
        for (int i = 0; i < 3; i++)
            gearCheck[i] = checkGearPole(i + 1, i + 2);
        int gearTurned = turnInfo[i][0];
        int turnDir = turnInfo[i][1], nextDir = turnDir * -1;
        turnGear(gearTurned, turnDir);

        if (gearTurned == 2 && gearCheck[0])
            turnGear(1, nextDir);
        if (gearTurned == 3 && gearCheck[2])
            turnGear(4, nextDir);

        int orderDir = (gearTurned <= 2) + 1;
        for (const int& gearIdx : turnOrder[gearTurned]){
            if (gearCheck[gearIdx]){
                turnGear(gearIdx + orderDir, nextDir);
                nextDir *= -1;
            }
            else break;
        }
    }
}

void output(){
    int gearScoreSum = 0;
    FOR(i, 4)
        gearScoreSum += (gears[i + 1][0] ? 1 << i : 0);
    cout << gearScoreSum;
}

int main(){
    input ();
    solve ();
    output();
}