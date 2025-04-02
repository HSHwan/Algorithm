#include <iostream>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1'000'000
#define ROOT -1
using namespace std;

int setNum, setOps;
int root[MAX + 1], rootRank[MAX + 1];

int findRoot(int n) {
    if (root[n] == ROOT)    return n;
    return root[n] = findRoot(root[n]);
}

void unionSet(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if (rootA == rootB) return;

    if (rootRank[rootA] < rootRank[rootB])  root[rootA] = rootB;
    else if (rootRank[rootA] > rootRank[rootB]) root[rootB] = rootA;
    else {
        root[rootB] = rootA;
        rootRank[rootA]++;
    }
}

bool isSameSet(int a, int b) {
    return findRoot(a) == findRoot(b);
}

int main() {
    FAST_IO
    cin >> setNum >> setOps;
    fill_n(root, setNum + 1, ROOT);
    for (int i = 0; i < setOps; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            if (isSameSet(a, b))    cout << "YES";
            else                    cout << "NO";
            cout << '\n';
        }
        else    unionSet(a, b);
    }
}