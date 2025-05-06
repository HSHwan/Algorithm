#include <iostream>
#include <algorithm>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define W first
#define V second
#define MAX_N 300'000

using namespace std;

typedef pair<int, int> pii;

int jewelNum, backpackNum;
pii jewel[MAX_N];
int backpack[MAX_N];

unsigned long long findMaxJewelCost() {
    unsigned long long vSum = 0;

    int idx = 0;
    priority_queue<int> pq;
    for (int i = 0; i < backpackNum; i++) {
        while (idx < jewelNum && backpack[i] >= jewel[idx].W) {
            pq.push(jewel[idx].V);
            idx++;
        }
        if (!pq.empty()) {
            vSum += pq.top();
            pq.pop();
        }
    }

    return vSum;
}

int main() {
    FAST_IO
    cin >> jewelNum >> backpackNum;

    for (int i = 0; i < jewelNum; i++)  cin >> jewel[i].W >> jewel[i].V;
    for (int i = 0; i < backpackNum; i++)   cin >> backpack[i];

    sort(jewel, jewel + jewelNum);
    sort(backpack, backpack + backpackNum);
    cout << findMaxJewelCost();
}