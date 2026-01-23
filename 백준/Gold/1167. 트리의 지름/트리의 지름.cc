#include <iostream>
#include <vector>
#include <algorithm>
#define VTX first
#define LEN second
using namespace std;

typedef pair<int, int> pii;

int vertexNum;
vector<vector<pii>> tree; 
vector<bool> visited;
int targetV, targetLen;

void dfs(int v, int len) {
    visited[v] = true;

    if (len > targetLen) {
        targetV = v;
        targetLen = len;
    }

    for (pii nextV : tree[v]) {
        int nextVertex = nextV.VTX;
        int nextLen = nextV.LEN;
        if (!visited[nextVertex]) {
            dfs(nextVertex, nextLen + len);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> vertexNum;
    tree.assign(vertexNum + 1, vector<pii>());
    for (int i = 0; i < vertexNum; i++) {
        int va, vb;
        cin >> va >> vb;
        while (vb != -1) {
            int len;
            cin >> len;
            tree[va].push_back({vb, len});
            cin >> vb;
        }
    }

    visited.assign(vertexNum + 1, false);
    targetV = 1;
    targetLen = 0;
    dfs(1, 0);

    int startV = targetV;
    targetLen = 0;
    fill_n(visited.begin(), vertexNum + 1, false);
    dfs(startV, 0);

    cout << targetLen;
}