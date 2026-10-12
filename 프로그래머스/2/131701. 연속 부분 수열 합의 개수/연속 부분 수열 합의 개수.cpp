#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> sums;
    int elem_len = elements.size();
    for (int i = 0; i < elem_len - 1; i++)  elements.push_back(elements[i]);
    
    for (int i = 1; i <= elem_len; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) sum += elements[j];
        sums.insert(sum);
        for (int j = i; j < elements.size(); j++) {
            sum += elements[j] - elements[j - i];
            sums.insert(sum);
        }
    }

    return sums.size();
}