#include <string>
#include <vector>
#include <set>

#define MAX 1001
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<int> weight_count(MAX);
    for (int w : weights)   weight_count[w]++;
    for (int w = 100; w <= 1000; w++) {
        long long count = weight_count[w];

        if (count == 0) continue;

        answer += count * (count - 1) / 2;

        if (w % 2 == 0 && w * 3 / 2 <= 1000) {
            answer += count * weight_count[w * 3 / 2];
        }

        if (w * 2 <= 1000) {
            answer += count * weight_count[w * 2];
        }

        if (w % 3 == 0 && w * 4 / 3 <= 1000) {
            answer += count * weight_count[w * 4 / 3];
        }
    }
    
    return answer;
}