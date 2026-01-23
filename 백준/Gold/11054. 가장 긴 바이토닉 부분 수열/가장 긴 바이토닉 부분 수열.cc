#include <iostream>
#include <vector>

using namespace std;

int solveBitonicSeqLen(int seqLen, vector<int> seq) {
    vector<int> incSeqCount(seqLen, 0), decSeqCount(seqLen, 0);

    for (int i = 0; i < seqLen; i++) {
        incSeqCount[i] = 1;
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j] && incSeqCount[i] < incSeqCount[j] + 1)
                incSeqCount[i]++;
        }

        int rev = seqLen - i - 1;
        decSeqCount[rev] = 1;
        for (int j = seqLen - 1; j > rev; j--) {
            if (seq[rev] > seq[j] && decSeqCount[rev] < decSeqCount[j] + 1)
                decSeqCount[rev]++;
        }
    }

    int seqMaxLen = 0;
    for (int i = 0; i < seqLen; i++) {
        seqMaxLen = max(incSeqCount[i] + decSeqCount[i], seqMaxLen);
    }

    return seqMaxLen - 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    int bitonicSeqLen;
    cin >> bitonicSeqLen;

    vector<int> bitonicSeq(bitonicSeqLen);
    for (int i = 0; i < bitonicSeqLen; i++) {
        cin >> bitonicSeq[i];
    }

    cout << solveBitonicSeqLen(bitonicSeqLen, bitonicSeq);
}