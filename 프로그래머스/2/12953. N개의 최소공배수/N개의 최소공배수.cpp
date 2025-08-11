#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {    
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    while (b != 0) {
        int n = a % b;
        a = b;
        b = n;
    }
    
    return a;
}

int solution(vector<int> arr) {
    int arr_len = arr.size();
    for (int i = 1; i < arr_len; i++) {
        arr[i] *= arr[i - 1] / gcd(arr[i], arr[i - 1]);
    }
    return arr.back();
}