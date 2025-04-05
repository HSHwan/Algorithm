#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1'000'000

using namespace std;

typedef long long ll;

int arrNum, updateNum, queryNum;
ll arr[MAX], tree[4 * MAX];

ll init(int start, int end, int index) {
    if (start == end)   return tree[index] = arr[start];

    int mid = (start + end) / 2;
    return tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1);
}

void update(int start, int end, int index, int target, ll diff) {
    if (target < start || target > end) return;
    tree[index] += diff;

    if (start == end)   return;
    int mid = (start + end) / 2;
    update(start, mid, 2 * index, target, diff);
    update(mid + 1, end, 2 * index + 1, target, diff);
}

ll query(int start, int end, int index, int left, int right) {
    if (left > end || right < start)    return 0;
    if (left <= start && right >= end)  return tree[index];

    int mid = (start + end) / 2;
    return query(start, mid, index * 2, left, right) + query(mid + 1, end, index * 2 + 1, left, right);
}

int main() {
    FAST_IO
    cin >> arrNum >> updateNum >> queryNum;

    for (int i = 0; i < arrNum; i++)    cin >> arr[i];
    init(0, arrNum - 1, 1);

    int cmdNum = updateNum + queryNum;
    while (cmdNum--) {
        ll cmd, arg1, arg2;
        cin >> cmd >> arg1 >> arg2;
        if (cmd == 1) {
            ll diff = arg2 - arr[arg1 - 1];
            arr[arg1 - 1] = arg2;
            update(0, arrNum - 1, 1, arg1 - 1, diff);
        }      
        else if (cmd == 2)  cout << query(0, arrNum - 1, 1, arg1 - 1, arg2 - 1) << '\n';
    }
}