#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n, k;
    cin >> n >> k;

    vector<int> sensor(n);
    for (int i = 0; i < n; i++) {
        cin >> sensor[i];
    }
    sort(sensor.begin(), sensor.end());

    vector<int> sensor_diff(n - 1);
    for (int i = 1; i < n; i++) {
        sensor_diff[i - 1] = sensor[i] - sensor[i - 1]; 
    }
    sort(sensor_diff.begin(), sensor_diff.end());

    int sum = 0, cover_cnt = n - k;
    for (int i = 0; i < cover_cnt; i++) {
        sum += sensor_diff[i];
    }

    cout << sum;
}