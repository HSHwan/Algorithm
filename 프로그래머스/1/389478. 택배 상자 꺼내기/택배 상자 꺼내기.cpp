#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    for (int i = num; i <= n; i += 2 * ((i / w + !!(i % w)) * w - i) + 1) {
        answer++;
    }
    return answer;
}