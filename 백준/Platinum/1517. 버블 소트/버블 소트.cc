#include <iostream>

#define MAX 500'000
using namespace std;

int arr[MAX + 1], sortedArr[MAX + 1];
long long swapNum = 0;

void merge(int left, int mid, int right) {
    int leftIdx = left, rightIdx = mid + 1;
    int sortedIdx = left;

    while (leftIdx <= mid && rightIdx <= right) {
        if (arr[leftIdx] <= arr[rightIdx])
            sortedArr[sortedIdx++] = arr[leftIdx++];
        else {
            sortedArr[sortedIdx++] = arr[rightIdx++];
            swapNum += (mid - leftIdx) + 1;
        }
    }

    while (leftIdx <= mid) {
        sortedArr[sortedIdx++] = arr[leftIdx++];
    }

    while (rightIdx <= right) {
        sortedArr[sortedIdx++] = arr[rightIdx++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = sortedArr[i];
    }

}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arrNum;
    cin >> arrNum;
    
    for (int i = 0; i < arrNum; i++)
        cin >> arr[i];

    mergeSort(0, arrNum - 1);

    cout << swapNum;
}