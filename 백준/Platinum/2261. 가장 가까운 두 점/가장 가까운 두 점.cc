#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define ll long long
#define MAX 800'000'000
using namespace std;

typedef pair<ll, ll> pll;

vector<pll> dots;

bool yComp(pll a, pll b) {
    if (a.Y != b.Y)
        return a.Y < b.Y;
    return a.X < b.X;
}

ll square(ll n) {
    return n * n;
}

ll findDist(pll a, pll b) {
    ll xDiff = a.X - b.X, yDiff = a.Y - b.Y;
    return square(xDiff) + square(yDiff);
}

ll findShortestDist(int start, int end) {
    if (end - start == 1)
        return MAX;

    int mid = (start + end) / 2;
    ll dist = min(findShortestDist(start, mid), findShortestDist(mid, end));
    vector<pll> nearDots;
    int midDotX = dots[mid].X;
    for (int i = start; i < end; i++) {
        if (square(dots[i].X - midDotX) <= dist)
            nearDots.push_back(dots[i]);
    }
    sort(nearDots.begin(), nearDots.end(), yComp);
    int nearDotCount = nearDots.size();
    for (int i = 0; i < nearDotCount; i++) {
        for (int j = i + 1; j < nearDotCount && j < i + 7; j++) {
            dist = min(findDist(nearDots[i], nearDots[j]), dist);
        }
    } 

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int dotNum;
    cin >> dotNum;

    int x, y;
    for (int i = 0; i < dotNum; i++) {
        cin >> x >> y;
        dots.push_back({x, y});
    }

    sort(dots.begin(), dots.end());

    ll dist = findShortestDist(0, dotNum);

    cout << dist;
}