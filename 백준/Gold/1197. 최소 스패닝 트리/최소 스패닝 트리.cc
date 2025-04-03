#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 10000
#define ROOT 0
using namespace std;

typedef pair<int, int> pii;

int root[MAX + 1], rootRank[MAX + 1];
vector<pair<int, pii>> edges;

int findRoot(int v) {
    if (root[v] == ROOT)    return v;
    return root[v] = findRoot(root[v]);
}

void unionGraph(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA == rootB) return;
    if (rootRank[rootA] < rootRank[rootB])      root[rootA] = rootB;
    else if (rootRank[rootA] > rootRank[rootB]) root[rootB] = rootA;
    else {
        root[rootB] = rootA;
        rootRank[rootA]++;
    }
}

int findMSTWeight() {
    int weightSum = 0;

    for (pair<int, pii> edge : edges) {
        int weight = edge.first;
        int v1 = edge.second.first;
        int v2 = edge.second.second;
        if (findRoot(v1) != findRoot(v2)) {
            unionGraph(v1, v2);
            weightSum += weight;
        }
    }

    return weightSum;
}

int main() {
    FAST_IO
    int vertexNum, edgeNum;
    cin >> vertexNum >> edgeNum;
    for (int i = 0; i < edgeNum; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int weight = findMSTWeight();
    cout << weight;
}