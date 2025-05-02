#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define A first
#define B second

using namespace std;

typedef pair<int, int> pii;

int lineNum;
vector<pii> lines;

int findLineCount() {
    int seqLen[lineNum], maxLen = 0;
    for (int i = 0; i < lineNum; i++) {
        seqLen[i] = 1;
        for (int j = 0; j < i; j++) {
            if (lines[i].B > lines[j].B)    seqLen[i] = max(seqLen[j] + 1, seqLen[i]);
        }
        
    }
    return lineNum - *max_element(seqLen, seqLen + lineNum);
}

int main() {
    FAST_IO
    cin >> lineNum;
    for (int i = 0; i < lineNum; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
    cout << findLineCount();    
}