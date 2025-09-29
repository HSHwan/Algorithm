#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM first
#define COUNT second
#define MAX_NUM 1000

using namespace std;

int main() {
    FAST_IO
    pair<int, int> balloon[MAX_NUM]; 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> balloon[i].COUNT;
        balloon[i].NUM = i + 1;
    }

    int count = 0, i = 0;
    while (--n) {
        cout << balloon[i].NUM << ' ';
        count = balloon[i].COUNT;
        for (int j = i; j < n; j++) balloon[j] = balloon[j + 1];
        if (count > 0) {
            count--;
            i = (count % n + i) % n;
        }
        else if (count < 0) {
            count = -count;
            i = (n + i - (count % n)) % n;
        }
        else if (count == 0 && i == n) i = 0;
    }
    cout << balloon[0].NUM;
}