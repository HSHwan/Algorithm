#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int max_num = order.size(), num = 1, idx = 0;
    vector<int> sub;
    while (idx < max_num) {
        while (order[idx] > num) {
            sub.push_back(num++);
        }
        if (order[idx] == num) {
            answer++;
            idx++;
            num++;
            continue;
        }
        if (!sub.empty()) {
            if (sub.back() == order[idx]) {
                sub.pop_back();
                idx++;
                answer++;
            }
            else {
                idx = max_num;
                break;
            }
        }
    }
    
    return answer;
}