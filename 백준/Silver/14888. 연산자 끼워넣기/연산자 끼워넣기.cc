#include <iostream>
#include <vector>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n;
vector<int> nums, ops(4);
int res_max = INT_MIN, res_min = INT_MAX;

int calc(int dest, int src, int op) {
    if (op == 0)    return dest + src;
    if (op == 1)    return dest - src;
    if (op == 2)    return dest * src;
    else    return dest / src;
}

void backtrack(int idx, int prev) {
    if (idx == n) {
        res_max = max(prev, res_max);
        res_min = min(prev, res_min);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (ops[i]) {
            ops[i]--;
            backtrack(idx + 1, calc(prev, nums[idx], i));
            ops[i]++;
        }
    }
}

int main() {
    FAST_IO
    cin >> n;
    
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < 4; i++) cin >> ops[i];

    backtrack(1, nums[0]);

    cout << res_max << '\n' << res_min;
}