#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    vector<int> signal_sum(signals.size());
    vector<pair<int, int>> signal_interval(signals.size());
    int max_t = 1;
    for (int i = 0; i < signals.size(); i++) {
        signal_sum[i] = signals[i][0] + signals[i][1] + signals[i][2];
        signal_interval[i] = {signals[i][0] + 1, signal_sum[i] - signals[i][2]};
        max_t = lcm(signal_sum[i], max_t);
    }

    for (int i = 1; i <= max_t; i++) {
        bool is_yellow = true;
        for (int j = 0; j < signals.size(); j++) {
            int end_t = i % signal_sum[j];
            if (end_t >= signal_interval[j].first && end_t <= signal_interval[j].second)    continue;
            is_yellow = false;
            break;
        }
        if (is_yellow) {
            answer = i;
            break;
        }  
    }
    
    return answer;
}