#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 9999
#define NUM first
#define CMD second

using namespace std;

typedef pair<int, string> REG;

bool visited[MAX + 1];

int D(int n) {
    return (2 * n) % 10000;
}

int S(int n) {
    return (n > 0) ? n - 1 : MAX;
}

int L(int n) {
    return (n * 10) % 10000 + (n / 1000);
}

int R(int n) {
    return (n % 10) * 1000 + (n / 10);
}

void bfs(int start, int end) {
    queue<REG> regQ;
    regQ.push({start, ""});
    memset(visited, 0, MAX + 1);
    visited[start] = true;

    while (!regQ.empty()) {
        REG nowReg = regQ.front();
        int nowNum = nowReg.NUM;
        regQ.pop();

        if (nowReg.NUM == end) {
            cout << nowReg.CMD << '\n';
            return;
        }

        int d = D(nowNum), s = S(nowNum), l = L(nowNum), r = R(nowNum);

        if (!visited[d]) {
            visited[d] = true;
            regQ.push({d, nowReg.CMD + "D"});
        }
        if (!visited[s]) {
            visited[s] = true;
            regQ.push({s, nowReg.CMD + "S"});
        }
        if (!visited[l]) {
            visited[l] = true;
            regQ.push({l, nowReg.CMD + "L"});
        }
        if (!visited[r]) {
            visited[r] = true;
            regQ.push({r, nowReg.CMD + "R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testcase;
    cin >> testcase;

    int initNum, destNum;
    while (testcase--) {
        cin >> initNum >> destNum;
        bfs(initNum, destNum);
    }

}