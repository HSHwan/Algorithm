#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_NUM 1000

using namespace std;

int targetSize;
int aPizzaNum, bPizzaNum;
int aPizza[MAX_NUM], bPizza[MAX_NUM];
int aPizzaSum[MAX_NUM][MAX_NUM], bPizzaSum[MAX_NUM][MAX_NUM];
vector<int> aPizzaCase, bPizzaCase;

void getPizzaSize(int pizzaNum, int* pizza, int pizzaSum[][MAX_NUM]) {
    for (int i = 0; i < pizzaNum; i++) {
        cin >> pizza[i];
        pizzaSum[0][i] = pizza[i] + (i > 0 ? pizzaSum[0][i - 1] : 0);
    }
}

void countPizzaSize(int pizzaNum, int* pizza, int pizzaSum[][MAX_NUM]) {
    for (int i = 1; i < pizzaNum; i++) {
        int subSize = pizza[i - 1];
        for (int j = 0; i + j < pizzaNum; j++)
            pizzaSum[i][j] = pizzaSum[i - 1][j + 1] - subSize;
        for (int j = pizzaNum - i; j < pizzaNum; j++)
            pizzaSum[i][j] = pizzaSum[i][j - 1] + pizza[j - pizzaNum + i];
    }
}

void setAllPizzaCase(vector<int>& pCase, int pizzaNum, int pizzaSum[][MAX_NUM]) {
    for (int i = 0; i < pizzaNum; i++) {
        for (int j = 0; j < pizzaNum - 1; j++) {
            pCase.push_back(pizzaSum[i][j]);
        }
    }
    pCase.push_back(pizzaSum[0][pizzaNum - 1]);
}

long long findTargetCaseNum() {
    int aPizzaTargetCount = upper_bound(aPizzaCase.begin(), aPizzaCase.end(), targetSize) - lower_bound(aPizzaCase.begin(), aPizzaCase.end(), targetSize);
    int bPizzaTargetCount = upper_bound(bPizzaCase.begin(), bPizzaCase.end(), targetSize) - lower_bound(bPizzaCase.begin(), bPizzaCase.end(), targetSize);
    long long targetCount = aPizzaTargetCount + bPizzaTargetCount;

    int aLen = aPizzaCase.size();
    int aIdx = 0, bIdx = bPizzaCase.size() - 1;
    while (aIdx < aLen && bIdx >= 0) {
        int pizzaSum = aPizzaCase[aIdx] + bPizzaCase[bIdx];
        if (pizzaSum > targetSize)  bIdx--;
        else if (pizzaSum < targetSize)  aIdx++;
        else {
            int aCount = 1, bCount = 1;
            while (aIdx + aCount < aLen && aPizzaCase[aIdx + aCount] == aPizzaCase[aIdx])
                aCount++;
            while (bIdx - bCount >= 0 && bPizzaCase[bIdx - bCount] == bPizzaCase[bIdx])
                bCount++;
            targetCount += aCount * bCount;
            aIdx += aCount;
            bIdx -= bCount;
        }
    }
    
    return targetCount;
}

int main() {
    FAST_IO
    cin >> targetSize >> aPizzaNum >> bPizzaNum;
    getPizzaSize(aPizzaNum, aPizza, aPizzaSum);
    getPizzaSize(bPizzaNum, bPizza, bPizzaSum);
    countPizzaSize(aPizzaNum, aPizza, aPizzaSum);
    countPizzaSize(bPizzaNum, bPizza, bPizzaSum);

    setAllPizzaCase(aPizzaCase, aPizzaNum, aPizzaSum);
    setAllPizzaCase(bPizzaCase, bPizzaNum, bPizzaSum);
    sort(aPizzaCase.begin(), aPizzaCase.end());
    sort(bPizzaCase.begin(), bPizzaCase.end());

    long long pizzaCase = findTargetCaseNum();
    cout << pizzaCase;
}