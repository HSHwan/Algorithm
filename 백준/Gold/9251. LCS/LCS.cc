#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1000

using namespace std;

int subseqLen[MAX][MAX];

int main() {
    FAST_IO
    string a, b;
    cin >> a >> b;
    int aLen = a.size(), bLen = b.size();
    subseqLen[0][0] = a[0] == b[0];

    for (int i = 1; i < aLen; i++)  subseqLen[i][0] = max(subseqLen[i - 1][0], a[i] == b[0] ? 1 : 0);
    for (int i = 1; i < bLen; i++)  subseqLen[0][i] = max(subseqLen[0][i - 1], b[i] == a[0] ? 1 : 0);

    for (int i = 1; i < aLen; i++) {
        for (int j = 1; j < bLen; j++) {
            subseqLen[i][j] = max(subseqLen[i - 1][j - 1] + (a[i] == b[j]), max(subseqLen[i - 1][j], subseqLen[i][j - 1]));
        }
    }

    cout << subseqLen[aLen - 1][bLen - 1];
}