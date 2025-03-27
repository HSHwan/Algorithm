#include <iostream>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 200

using namespace std;

int aMax, bMax, cMax;
bool visited[MAX + 1][MAX + 1][MAX + 1];
set<int> waterAmount;

void dfs(int a, int b, int c) {
    if (visited[a][b][c])   return;
    visited[a][b][c] = true;
    if (!a && !waterAmount.count(c))
        waterAmount.insert(c);
    int aDiff = aMax - a;
    int bDiff = bMax - b;
    int cDiff = cMax - c;
    
    dfs(max(a - bDiff, 0), b + min(bDiff, a), c);
    dfs(max(a - cDiff, 0), b, c + min(cDiff, a));
    dfs(a + min(aDiff, b), max(b - aDiff, 0), c);
    dfs(a, max(b - cDiff, 0), c + min(cDiff, b));
    dfs(a + min(aDiff, c), b, max(c - aDiff, 0));
    dfs(a, b  + min(bDiff, c), max(c - bDiff, 0));
}

int main() {
    FAST_IO
    cin >> aMax >> bMax >> cMax;
    dfs(0, 0, cMax);
    for (int it : waterAmount)  cout << it << ' ';
}