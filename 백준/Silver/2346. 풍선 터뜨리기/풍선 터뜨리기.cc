#include <iostream>
#include <deque>
#include <utility>
using namespace std;
#define Num first
#define Val second

int main() {
    int N, balloon_num, ord = 1;
    
    cin >> N;
    deque<pair<int, int>> balloons;

    for (int i = 1; i <= N; i++) {
        cin >> balloon_num;
        balloons.push_back(make_pair(i, balloon_num));
    }

    while (!balloons.empty()) {
        if (ord > 1){ // Right shift
            balloons.push_back(balloons.front());
            balloons.pop_front();
            ord--;
        }
        else if (ord < 0){ // Left shift
            balloons.push_front(balloons.back());
            balloons.pop_back();
            ord++;
        }
        else { // Balloon Bomb!!
            ord = balloons.front().Val;
            cout << balloons.front().Num << ' ';
            balloons.pop_front();
        }
    }
}
// ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);