#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 1);
    const int MAX_NUM = 10000000;
    long long start_pos = begin;

    if (begin == 1) answer[0] = 0;
    for (int i = 0; i < answer.size(); i++){
        for (int j = 2; j <= sqrt(start_pos); j++){
            if (start_pos % j == 0 & start_pos / j <= MAX_NUM){
                answer[i] = start_pos / j;
                break;
            }
            else if (start_pos % j == 0 & start_pos / j > MAX_NUM)
                answer[i] = j;
        }
        start_pos++;
    }
    return answer;
}