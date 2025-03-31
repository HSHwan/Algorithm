#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ROOT -1
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> Rect;

vector<int> rootRectangle;
vector<Rect> rectangles;

int findRoot(int r) {
    if (rootRectangle[r] == ROOT)   return r;
    return rootRectangle[r] = findRoot(rootRectangle[r]);
}

void unionRectangle(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if (rootA != rootB) {
        rootRectangle[rootB] = rootA;
    }
}

bool isConnected(Rect aRect, Rect bRect) {
    pii aStart = aRect.first, aEnd = aRect.second;
    pii bStart = bRect.first, bEnd = bRect.second;
    if (aEnd.X < bStart.X || aEnd.Y < bStart.Y) return false;
    if (bEnd.X < aStart.X || bEnd.Y < aStart.Y) return false;
    if (aStart.X < bStart.X && aStart.Y < bStart.Y && aEnd.X > bEnd.X && aEnd.Y > bEnd.Y)   return false;
    if (bStart.X < aStart.X && bStart.Y < aStart.Y && bEnd.X > aEnd.X && bEnd.Y > aEnd.Y)   return false;
    return true;
}

bool isFirstPU(int rectangleNum) {
    for (int i = 0; i < rectangleNum; i++) {
        if (isConnected(rectangles[i], {{0, 0}, {0, 0}}))   return false; 
    }
    return true;
}

int main() {
    FAST_IO
    int rectangleNum;
    cin >> rectangleNum;
    rootRectangle.assign(rectangleNum, -1);
    rectangles.resize(rectangleNum);
    for (int i = 0; i < rectangleNum; i++) {
        cin >> rectangles[i].first.X >> rectangles[i].first.Y
            >> rectangles[i].second.X >> rectangles[i].second.Y;
    }
    int puCmdCount = 0;
    if (isFirstPU(rectangleNum))    puCmdCount++;
    for (int i = 0; i < rectangleNum; i++) {
        for (int j = 0; j < rectangleNum; j++) {
            if (i != j && isConnected(rectangles[i], rectangles[j]))
                unionRectangle(i, j);
        }
    }
    puCmdCount += count(rootRectangle.begin(), rootRectangle.end(), ROOT) - 1;
    cout << puCmdCount;
}