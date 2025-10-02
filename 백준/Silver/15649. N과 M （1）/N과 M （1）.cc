#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m;
vector<int> nums;
vector<bool> visited;

void backtrack(int idx) {
    if (idx == m) {
        for (int i : nums)  cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            nums.push_back(i);
            backtrack(idx + 1);
            visited[i] = false;
            nums.pop_back();
        }
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    visited.assign(n + 1, false);
    backtrack(0);
}