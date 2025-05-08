#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int p, const vector<int>& b) {
    int n = b.size();
    
    // 1. 기본 조건 검사
    if (b[0] != 1) return "NO";
    if (b.back() != (n + p - 1) / p) return "NO";
    
    // 2. 단조 증가 및 증가폭 검사
    for (int i = 1; i < n; ++i) {
        if (b[i] < b[i-1] || b[i] > b[i-1] + 1)
            return "NO";
    }
    
    // 3. 하한 조건 검사 (b_i >= ceil((i+1)/p))
    for (int i = 0; i < n; ++i) {
        if (b[i] < (i + 1 + p - 1) / p)
            return "NO";
    }
    
    // 4. p=1 특수 처리
    if (p == 1) {
        for (int i = 0; i < n; ++i)
            if (b[i] != i+1) return "NO";
        return "YES";
    }
    
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, p;
    cin >> n >> p;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    cout << solve(p, b) << '\n';
    return 0;
}