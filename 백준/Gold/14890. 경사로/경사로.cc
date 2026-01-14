#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Num first
#define Cnt second
using namespace std;

typedef pair<int, int> pii;

int N, L;
vector<vector<int>> map;
vector<pii> arr;

bool check_arr() {
    bool checked = true;
    for (int j = 1; j < arr.size(); j++) {
        if (abs(arr[j].Num - arr[j - 1].Num) > 1 || (arr[j].Num > arr[j - 1].Num && arr[j - 1].Cnt < L) || (arr[j].Num < arr[j - 1].Num && arr[j].Cnt < L)) {
            checked = false;
            break;
        }
        if (arr[j].Num > arr[j - 1].Num) {
            arr[j - 1].Cnt -= L;
        }
        else {
            arr[j].Cnt -= L;
        }
    }
    return checked;
}

int main() {
    FAST_IO
    cin >> N >> L;
    map.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        arr = {{map[i][0], 1}};
        for (int j = 1; j < N; j++) {
            if (map[i][j] != arr.back().Num) {
                arr.push_back({map[i][j], 1});
            }
            else arr.back().Cnt++;
        }
        count += check_arr();
    }

    for (int i = 0; i < N; i++) {
        arr = {{map[0][i], 1}};
        for (int j = 1; j < N; j++) {
            if (map[j][i] != arr.back().Num) {
                arr.push_back({map[j][i], 1});
            }
            else arr.back().Cnt++;
        }
        count += check_arr();
    }

    cout << count;
}