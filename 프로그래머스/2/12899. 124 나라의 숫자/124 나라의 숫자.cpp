#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
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