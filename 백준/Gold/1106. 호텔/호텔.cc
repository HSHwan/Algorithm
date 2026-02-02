#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_C 1000
#define C first
#define N second
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int main() {
    FAST_IO
    int target, num;
    cin >> target >> num;

    vector<pii> city(num);
    for (int i = 0; i < num; i++) {
        cin >> city[i].C >> city[i].N;
    }

    vector<int> customer(2 * MAX_C, INF);
    customer[0] = 0;
    int min_cost = INF;
    for (int i = 0; i < target; i++) {
        for (pii c : city) {
            customer[i + c.N] = min(customer[i + c.N], customer[i] + c.C);
            if (i + c.N >= target) {
                min_cost = min(customer[i + c.N], min_cost);
            }
        }
    }

    cout << min_cost;
}