#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

string solve(int p, vector<int> b) {
    int n = b.size();
    
    if (b[0] != 1) return "NO";
    if (b.back() != (n + p - 1) / p) return "NO";
    
    for (int i = 1; i < n; ++i) {
        if (b[i] < b[i-1] || b[i] > b[i-1] + 1) return "NO";
    }
    
    for (int i = 0; i < n; ++i) {
        if (b[i] < (i + 1 + p - 1) / p) return "NO";
    }
    
    if (p == 1) {
        for (int i = 0; i < n; ++i)
            if (b[i] != i+1) return "NO";
        return "YES";
    }
    
    return "YES";
}

int main() {
    FAST_IO
    
    int n, p;
    cin >> n >> p;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    cout << solve(p, b);
    return 0;
}