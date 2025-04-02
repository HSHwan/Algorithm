#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100'001
#define INF 10e7
#define T first
#define P second

using namespace std;

typedef pair<int, int> pii;

int time[MAX];

void findTarget(int start) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill_n(time, MAX, INF);
    time[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int nowPos = pq.top().P;
        int nowTime = pq.top().T;
        pq.pop();

        if (nowTime > time[nowPos]) continue;
        vector<int> nextPos = {2 * nowPos, nowPos + 1, nowPos - 1};
        for (int i = 0; i < 3; i++) {
            if (nextPos[i] > MAX - 1 || nextPos[i] < 0)  continue;
            int nextTime = time[nowPos] + !!i;
            if (time[nextPos[i]] > nextTime) {
                time[nextPos[i]] = nextTime;
                pq.push({nextTime, nextPos[i]});
            }
        }
    }
}

int main() {
    FAST_IO
    int start, target;
    cin >> start >> target;
    findTarget(start);
    cout << time[target];
}