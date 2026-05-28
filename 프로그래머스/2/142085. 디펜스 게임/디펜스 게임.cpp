#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0, used = 0;
    priority_queue<int> pq;
    for (int e : enemy) {
        pq.push(e);
        sum += e;
        if (sum > n) {
            if (used == k)  break;
            sum -= pq.top();
            pq.pop();
            used++;
            answer++;
            continue;
        }
        answer++;
    }
    return answer;
}