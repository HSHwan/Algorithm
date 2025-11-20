#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 3 < n) {
                max_sum = max(paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j], max_sum);
            }
            if (i + 2 < n && j + 1 < m) {
                int three_1 = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];
                int three_2 = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
                max_sum = max(three_1 + paper[i][j + 1], max_sum);
                max_sum = max(three_1 + paper[i + 1][j + 1], max_sum);
                max_sum = max(three_1 + paper[i + 2][j + 1], max_sum);
                max_sum = max(three_2 + paper[i][j], max_sum);
                max_sum = max(three_2 + paper[i + 1][j], max_sum);
                max_sum = max(three_2 + paper[i + 2][j], max_sum);
                max_sum = max(paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1], max_sum);
                max_sum = max(paper[i + 1][j] + paper[i + 2][j] + paper[i][j + 1] + paper[i + 1][j + 1], max_sum);
            }
            if (i + 1 < n && j + 1 < m) {
                max_sum = max(paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1], max_sum);
            }
            if (i + 1 < n && j + 2 < m) {
                int three_1 = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
                int three_2 = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
                max_sum = max(three_1 + paper[i + 1][j], max_sum);
                max_sum = max(three_1 + paper[i + 1][j + 1], max_sum);
                max_sum = max(three_1 + paper[i + 1][j + 2], max_sum);
                max_sum = max(three_2 + paper[i][j], max_sum);
                max_sum = max(three_2 + paper[i][j + 1], max_sum);
                max_sum = max(three_2 + paper[i][j + 2], max_sum);
                max_sum = max(paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2], max_sum);
                max_sum = max(paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i][j + 2], max_sum);
            }
            if (j + 3 < m) {
                max_sum = max(paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3], max_sum);
            }
        }
    }

    cout << max_sum;
}