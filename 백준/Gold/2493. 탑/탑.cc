#include <iostream>
#include <stack>
#include <vector>

#define TOP pair<int, int>
#define BUILD_TOP make_pair
#define NUM first
#define HEIGHT second
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, top_height;
    vector<int> top_receive_idx;
    stack<TOP> top_height_stk, top_queue;
    
    cin >> N;
    top_receive_idx.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> top_height;
        top_height_stk.push(BUILD_TOP(i, top_height));
    }

    while (true) {
        top_queue.push(top_height_stk.top());
        top_height_stk.pop();
        if (top_height_stk.empty()) break;
        while (!top_queue.empty() && top_height_stk.top().HEIGHT >= top_queue.top().HEIGHT) {
            top_receive_idx[top_queue.top().NUM] = top_height_stk.top().NUM + 1;
            top_queue.pop();
        }
    }

    for (auto& top_num : top_receive_idx) cout << top_num << ' ';
}