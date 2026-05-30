#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    // 1 2 3 -> 1 2 4
    // 4 5 6 -> 1 1 1
    // 7 8 9 -> 2 2 2
    // 10 11 12 -> 4 4 4
    // 3^n + 3^(n-1) + 3^(n-2) + ... + 3^0 * 3
    
    while (n) {
        if (n % 3 == 1) {
            answer += '1';
        }
        else if (n % 3 == 2) {
            answer += '2';
        }
        else {
            answer += '4';
        }
        n -= (n % 3 == 0) ? 3 : n % 3;
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}