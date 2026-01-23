#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define TIME first 
#define COM second
#define INF (~0U >> 2)
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;
typedef pair<int, int> pii;

int testCase;
int computerNum, dependencyNum, targetNum;
int infectedComputerNum, infectTime;
vector<vector<pii>> computers;
vector<int> targetComTime;

void DijkstraHacking(const pii& firstInfected){
    pii nowInfected = firstInfected;
    priority_queue<pii, vector<pii>, greater<pii>> nextInfected;
    vector<int>(computerNum + 1, INF).swap(targetComTime);
    nextInfected.push(nowInfected);
    targetComTime[nowInfected.COM] = 0;
    
    while (!nextInfected.empty()){
        nowInfected = nextInfected.top();
        nextInfected.pop();

        if (targetComTime[nowInfected.COM] < nowInfected.TIME)
            continue;
        for (pii nextCom : computers[nowInfected.COM]){
            nextCom.TIME += nowInfected.TIME;
            if (nextCom.TIME < targetComTime[nextCom.COM]){
                targetComTime[nextCom.COM] = nextCom.TIME;
                nextInfected.push(nextCom);
            }
        }
    }
}

void printInfectedComputerInfo(){
    cout << infectedComputerNum << ' ' << infectTime << '\n';
}

void infectComputers(){
    vector<vector<pii>>(computerNum + 1).swap(computers);
    int dependCom, dependedCom;
    int infectingTime;
    FOR(j, dependencyNum){
        cin >> dependCom >> dependedCom >> infectingTime;
        computers[dependedCom].push_back({infectingTime, dependCom});
    }

    infectedComputerNum = 0;
    infectTime = 0;
    DijkstraHacking({0, targetNum});
    FOR(i, computerNum + 1){
        if (targetComTime[i] != INF){
            infectedComputerNum++;
            infectTime = max(infectTime, targetComTime[i]);
        }    
    }
    
    printInfectedComputerInfo();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    
    FOR(i, testCase){
        cin >> computerNum >> dependencyNum >> targetNum;
        infectComputers();
    }
}