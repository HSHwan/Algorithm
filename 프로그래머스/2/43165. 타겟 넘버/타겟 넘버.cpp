#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0, resultNum;
    for (int i = 0; i < 1 << numbers.size(); i++){
        resultNum = 0;
        for (int j = 0; j < numbers.size(); j++){
            if (i & (1 << j))
                resultNum -= numbers[j];
            else
                resultNum += numbers[j];
        }
        if (resultNum == target)
            answer++;
    }
    return answer;
}