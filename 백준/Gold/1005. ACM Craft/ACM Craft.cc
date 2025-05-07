#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> buildTime, prevBuild, inDegree;
vector<vector<int>> graph;

int findBuildTime(int n, int target) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0)   q.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int now = q.front();
        q.pop();

        if (now == target)  break;
        for (int next : graph[now]) {
            prevBuild[next] = max(prevBuild[next], prevBuild[now] + buildTime[now]);
            if (--inDegree[next] == 0)  q.push(next);
        }
    }

    return prevBuild[target] + buildTime[target];
}

void build() {
    int buildNum, ruleNum;
    cin >> buildNum >> ruleNum;

    buildTime.resize(buildNum + 1);
    for (int i = 1; i <= buildNum; i++) cin >> buildTime[i];

    graph.clear();
    graph.resize(buildNum + 1);
    inDegree.resize(buildNum + 1);
    fill(inDegree.begin(), inDegree.end(), 0);
    for (int i = 0; i < ruleNum; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        inDegree[y]++;
    }

    int w;
    cin >> w;

    prevBuild.resize(buildNum + 1);
    fill(prevBuild.begin(), prevBuild.end(), 0);
    cout << findBuildTime(buildNum, w) << '\n';
}

int main() {
    FAST_IO

    int testcase;
    cin >> testcase;

    while (testcase--)  build();
}