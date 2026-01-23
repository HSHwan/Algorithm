#include <iostream>
#include <cmath>
#define X first
#define Y second
using namespace std;

typedef pair<double, double> pdd;

double findDist(pdd a, pdd b) {
    double xDiff = a.X - b.X, yDiff = a.Y - b.Y;
    double dist = sqrt(xDiff * xDiff + yDiff * yDiff);
    return dist;
}

int main() {
    cout << fixed;
    cout.precision(10);
    pdd aStart, aEnd, bStart, bEnd;
    cin >> aStart.X >> aStart.Y >> aEnd.X >> aEnd.Y;
    cin >> bStart.X >> bStart.Y >> bEnd.X >> bEnd.Y;

    for (int i = 0; i < 100; i++) {
        pdd p1 = {(2.0 * aStart.X + aEnd.X) / 3.0, (2.0 * aStart.Y + aEnd.Y) / 3.0};
        pdd p2 = {(2.0 * aEnd.X + aStart.X) / 3.0, (2.0 * aEnd.Y + aStart.Y) / 3.0};
        pdd q1 = {(2.0 * bStart.X + bEnd.X) / 3.0, (2.0 * bStart.Y + bEnd.Y) / 3.0};
        pdd q2 = {(2.0 * bEnd.X + bStart.X) / 3.0, (2.0 * bEnd.Y + bStart.Y) / 3.0};
        if (findDist(p1, q1) <= findDist(p2, q2)) {
            aEnd = p2;
            bEnd = q2;
        }
        else {
            aStart = p1;
            bStart = q1;
        }
    }

    double dist = findDist(aStart, bStart);
    cout << dist;
}