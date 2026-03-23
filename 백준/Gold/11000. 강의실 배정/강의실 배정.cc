#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define S first
#define T second

using namespace std;
typedef pair<int, int> pii;

bool comp(pii a, pii b) {
    if (a.S != b.S) return a.S < b.S;
    return a.T > b.T;
}

int main() {
    FAST_IO
    int N;
    cin >> N;

    vector<pii> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].S >> arr[i].T;
    }

    sort(arr.begin(), arr.end(), comp);

    priority_queue<int, vector<int>, greater<int>> end_pq;
    for (pii p : arr) {
        if (end_pq.empty()) {
            end_pq.push(p.T);
            continue;
        }
        int cur_end = end_pq.top();
        if (cur_end <= p.S) {
            end_pq.pop();
        }
        end_pq.push(p.T);
    }

    cout << end_pq.size();
}