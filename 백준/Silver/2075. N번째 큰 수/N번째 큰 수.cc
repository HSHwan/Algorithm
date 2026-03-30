#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef vector<int>::iterator vii;

struct comp {
    bool operator()(vii a, vii b) {
        return *a < *b;
    }
};

int main() {
    FAST_IO

    int N;
    cin >> N;
    
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[j][i];
        }
    }
    priority_queue<vii, vector<vii>, comp> pq;
    for (int i = 0; i < N; i++) {
        pq.push(matrix[i].begin());
    }
    int count = 1;
    while (count < N) {
        vii nxt = pq.top();
        nxt++;
        pq.push(nxt);
        pq.pop();
        count++;
    }
    cout << *pq.top();
}