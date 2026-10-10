#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int backtrack(int n, int end, vector<pii>& queens) {
    if (n == end)   return 1;
    int count = 0;
    for (int i = 0; i < end; i++) {
        bool checked = false;
        for (pii q : queens) {
            if (q.X == n || q.Y == i || n + i == q.X + q.Y || i - n == q.Y - q.X) {
                checked = true;
                break;
            }
        }
        if (checked)    continue;
        queens.push_back({n, i});
        count += backtrack(n + 1, end, queens);
        queens.pop_back();
    }
    return count;
}

int solution(int n) {
    vector<pii> queens;
    return backtrack(0, n, queens);
}