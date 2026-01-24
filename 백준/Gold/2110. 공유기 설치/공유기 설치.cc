#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define MAX 1'000'000'000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int houseNum, routerNum;
    cin >> houseNum >> routerNum;

    vector<int> houseX(houseNum);
    for (int i = 0; i < houseNum; i++) {
        cin >> houseX[i];
    }

    sort(houseX.begin(), houseX.end());

    long low = 1, high = MAX;
    while (low <= high) {
        long mid = (low + high) >> 1;
        int routerCount = 0;
        int targetHouse = houseX[0];
        for (int x : houseX) {
            if (abs(targetHouse - x) >= mid) {
                routerCount++;
                targetHouse = x;
            }
        }
        
        if (routerCount < routerNum - 1) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << high;
}