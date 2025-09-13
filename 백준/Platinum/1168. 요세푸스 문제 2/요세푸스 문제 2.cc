#include <iostream>
#include <vector>

using namespace std;

int init(vector<int>& tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;
    return tree[node] = init(tree, 2 * node, start, mid) + init(tree, 2 * node + 1, mid + 1, end);
}

void update(vector<int>& tree, int node, int start, int end, int index) {
    if (start == end) {
        tree[node] = 0;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid)
        update(tree, 2 * node, start, mid, index);
    else
        update(tree, 2 * node + 1, mid + 1, end, index);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(vector<int>& tree, int node, int start, int end, int sum) {
    if (start == end)
        return start;

    int mid = (start + end) / 2;
    if (tree[2 * node] >= sum)
        return query(tree, 2 * node, start, mid, sum);
    else
        return query(tree, 2 * node + 1, mid + 1, end, sum - tree[2 * node]);

}

int main() {
    int num, step;
    cin >> num >> step;

    vector<int> tree(4 * num);
    init(tree, 1, 1, num);

    int pos = 1;
    cout << '<';
    for (int i = 1; i <= num; i++) {
        int remaining = tree[1];
        pos = (pos + step - 1) % remaining;
        if (!pos)   pos = remaining;
        int target = query(tree, 1, 1, num, pos);
        cout << target;
        if (i != num)   cout << ", ";
        update(tree, 1, 1, num, target);
    }
    cout << '>';
}