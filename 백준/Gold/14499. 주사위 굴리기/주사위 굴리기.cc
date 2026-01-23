#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

pair<int, int> mapLen, dicePos;
vector<int> diceNum(7, 0), commands, results;
vector<pair<int, int>> diceDir = {{}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<vector<int>> map, diceRollOrder = {{}, {3, 1, 4, 6}, {4, 1, 3, 6}, {2, 1, 5, 6}, {5, 1, 2, 6}};
int commandNum;

void input(){
    cin >> mapLen.X >> mapLen.Y >> dicePos.X >> dicePos.Y >> commandNum;    
    
    vector<vector<int>>(mapLen.X, vector<int>(mapLen.Y)).swap(map);
    FOR(i, mapLen.X){
        FOR(j, mapLen.Y){
            cin >> map[i][j];
        }
    }

    vector<int>(commandNum, 0).swap(commands);
    FOR(i, commandNum){
        cin >> commands[i];
    }
}

bool isMovable(const pair<int, int>& pos){
    return !(pos.X >= mapLen.X || pos.Y >= mapLen.Y || pos.X < 0 || pos.Y < 0);
}

bool rollDice(const int& dir){
    pair<int, int> nextDicePos(dicePos.X + diceDir[dir].X, dicePos.Y + diceDir[dir].Y);
    if (isMovable(nextDicePos)){
        FOR(i, 3){
            swap(diceNum[diceRollOrder[dir][i]], diceNum[diceRollOrder[dir][i + 1]]);
        }
        dicePos = nextDicePos;
        return true;
    }
    return false;
}

void solve(){
    FOR(i, commandNum){
        if (!rollDice(commands[i])) continue;
        if (map[dicePos.X][dicePos.Y]){
            diceNum[6] = map[dicePos.X][dicePos.Y];
            map[dicePos.X][dicePos.Y] = 0;
        }
        else
            map[dicePos.X][dicePos.Y] = diceNum[6];
        results.push_back(diceNum[1]);
    }
}

void output(){
    for (const int& diceTop : results)
        cout << diceTop << '\n';
}

int main(){
    input ();
    solve ();
    output();
}