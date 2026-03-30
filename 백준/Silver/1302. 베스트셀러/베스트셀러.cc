#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define T first
#define C second

using namespace std;

typedef pair<string, int> psi;

bool comp(psi a, psi b) {
    return a.C < b.C;
}

int main() {
    FAST_IO
    
    int N;
    cin >> N;

    map<string, int> bookCount;
    for (int i = 0; i < N; i++) {
        string title;
        cin >> title;
        if (!bookCount.count(title))    bookCount[title] = 0;
        bookCount[title]++;
    }

    vector<psi> vec(bookCount.begin(), bookCount.end());
    cout << max_element(vec.begin(), vec.end(), comp)->T;
}