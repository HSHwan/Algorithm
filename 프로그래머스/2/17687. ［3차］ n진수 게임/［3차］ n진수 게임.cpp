#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert_num(int num, int n) {
    if (num == 0)   return "0";
    string result = "";
    string digits = "0123456789ABCDEF";
    
    while (num > 0) {
        result += digits[num % n];
        num /= n;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0, cur_order = 1;
    while (answer.size() != t) {
        string word = convert_num(num, n);
        for (int i = 0; i < word.size(); i++) {
            if (cur_order == p && answer.size() < t)
                answer += word[i];
            cur_order++;
            if (cur_order > m)  cur_order = 1;
        }
        
        num++;
    }
    return answer;
}