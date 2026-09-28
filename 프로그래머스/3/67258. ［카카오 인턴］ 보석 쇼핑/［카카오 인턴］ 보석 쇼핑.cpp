#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, 1};
    unordered_map<string, int> gem_num;
    int total_num = gems.size();
    int gem_count = unordered_set<string>(gems.begin(), gems.end()).size(), cur_count = 0;
    int start = 0, end = 0;
    int min_len = total_num + 1;
    while (end < total_num) {
        gem_num[gems[end]]++;
        end++;
        
        while(gem_num.size() == gem_count) {
            if (end - start < min_len) {
                answer = {start + 1, end};
                min_len = end - start;
            }
            gem_num[gems[start]]--;
            if (gem_num[gems[start]] == 0) {
                gem_num.erase(gems[start]);
            }
            start++;
        }
    }
    
    return answer;
}