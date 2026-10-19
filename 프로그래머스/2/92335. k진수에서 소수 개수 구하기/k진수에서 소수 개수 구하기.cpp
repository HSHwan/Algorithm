#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string base_k = "";
    while (n) {
        base_k += to_string(n % k);
        n /= k;
    }
    reverse(base_k.begin(), base_k.end());
    
    while (base_k.back() == '0')    base_k.pop_back();
    
    string delim = "0";
    size_t start = 0, end = base_k.find(delim);
    string sub;
    vector<long long> tokens;
    
    while (end != string::npos) {
        sub = base_k.substr(start, end - start);
        if (sub.size())
            tokens.push_back(stoll(sub));
        start = end + delim.size();
        end = base_k.find(delim, start);
    }
    sub = base_k.substr(start, end - start);
    if (sub.size())
        tokens.push_back(stoll(sub));
    
    for (long long token : tokens) {
        if (token == 2) {
            answer++;
            continue;
        }
        if (token == 1 || token % 2 == 0)   continue;
        long long max_i = sqrt(token);
        bool is_prime = true;
        for (long long i = 3; i <= max_i; i += 2) {
            if (token % i == 0 && token / i > 1) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)   answer++;
    }
    
    return answer;
}