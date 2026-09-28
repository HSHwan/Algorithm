#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    return string(phone_number.size() - 4, '*') + phone_number.substr(phone_number.size() - 4, 4);
}